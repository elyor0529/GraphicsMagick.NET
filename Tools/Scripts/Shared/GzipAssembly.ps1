#==================================================================================================
function GzipAssembly($inFile,$outFile)
{
  $inFile = FullPath $inFile
  $outFile = FullPath $outFile

  if (!(Test-Path $inFile))
  {
    Write-Error "Unable to find file: $inFile."
    Exit 1
  }

  Write-Host "Compressing $inFile to $outFile."

  $input = New-Object System.IO.FileStream $inFile, ([IO.FileMode]::Open), ([IO.FileAccess]::Read), ([IO.FileShare]::Read)

  $buffer = New-Object byte[]($input.Length)
  $byteCount = $input.Read($buffer, 0, $input.Length)
  $input.Close()

  $folder = (Split-Path $outFile -Parent)
  if (!(Test-Path $folder))
  {
    New-Item -ItemType directory -Path $folder
  }
  $output = New-Object System.IO.FileStream $outFile, ([IO.FileMode]::Create), ([IO.FileAccess]::Write), ([IO.FileShare]::None)
  $gzipStream = New-Object System.IO.Compression.GzipStream $output, ([IO.Compression.CompressionMode]::Compress)

  $gzipStream.Write($buffer, 0, $buffer.Length)
  $gzipStream.Close()

  $output.Close()
}
#==================================================================================================
function GzipAssemblies()
{
  GzipAssembliesQ8
  GzipAssembliesQ16
}
#==================================================================================================
function GzipAssembliesQ8()
{
  GzipAssembly "GraphicsMagick.NET\bin\ReleaseQ8\Win32\GraphicsMagick.NET-x86.dll" "GraphicsMagick.NET.AnyCPU\Resources\ReleaseQ8\GraphicsMagick.NET-x86.gz"
  GzipAssembly "GraphicsMagick.NET\bin\ReleaseQ8\x64\GraphicsMagick.NET-x64.dll" "GraphicsMagick.NET.AnyCPU\Resources\ReleaseQ8\GraphicsMagick.NET-x64.gz"
}
#==================================================================================================
function GzipAssembliesQ16()
{
  GzipAssembly "GraphicsMagick.NET\bin\ReleaseQ16\Win32\GraphicsMagick.NET-x86.dll" "GraphicsMagick.NET.AnyCPU\Resources\ReleaseQ16\GraphicsMagick.NET-x86.gz"
  GzipAssembly "GraphicsMagick.NET\bin\ReleaseQ16\x64\GraphicsMagick.NET-x64.dll" "GraphicsMagick.NET.AnyCPU\Resources\ReleaseQ16\GraphicsMagick.NET-x64.gz"
}
#==================================================================================================
