//=================================================================================================
// Copyright 2015 Dirk Lemstra <https://graphicsmagick.codeplex.com/>
//
// Licensed under the ImageMagick License (the "License"); you may not use this file except in
// compliance with the License. You may obtain a copy of the License at
//
//   http://www.imagemagick.org/script/license.php
//
// Unless required by applicable law or agreed to in writing, software distributed under the
// License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
// express or implied. See the License for the specific language governing permissions and
// limitations under the License.
//=================================================================================================
#include "Stdafx.h"
#include "..\..\Helpers\XmlHelper.h"
#include "..\MagickScript.h"
#include "..\..\Drawables\DrawableAffine.h"
#include "..\..\Drawables\DrawableArc.h"
#include "..\..\Drawables\DrawableBezier.h"
#include "..\..\Drawables\DrawableCircle.h"
#include "..\..\Drawables\DrawableClipPath.h"
#include "..\..\Drawables\DrawableColor.h"
#include "..\..\Drawables\DrawableCompositeImage.h"
#include "..\..\Drawables\DrawableDashArray.h"
#include "..\..\Drawables\DrawableDashOffset.h"
#include "..\..\Drawables\DrawableEllipse.h"
#include "..\..\Drawables\DrawableFillColor.h"
#include "..\..\Drawables\DrawableFillOpacity.h"
#include "..\..\Drawables\DrawableFillRule.h"
#include "..\..\Drawables\DrawableFont.h"
#include "..\..\Drawables\DrawableGravity.h"
#include "..\..\Drawables\DrawableLine.h"
#include "..\..\Drawables\DrawableMatte.h"
#include "..\..\Drawables\DrawableMiterLimit.h"
#include "..\..\Drawables\DrawablePath.h"
#include "..\..\Drawables\DrawablePoint.h"
#include "..\..\Drawables\DrawablePointSize.h"
#include "..\..\Drawables\DrawablePolygon.h"
#include "..\..\Drawables\DrawablePolyline.h"
#include "..\..\Drawables\DrawablePushClipPath.h"
#include "..\..\Drawables\DrawablePushPattern.h"
#include "..\..\Drawables\DrawableRectangle.h"
#include "..\..\Drawables\DrawableRotation.h"
#include "..\..\Drawables\DrawableRoundRectangle.h"
#include "..\..\Drawables\DrawableScaling.h"
#include "..\..\Drawables\DrawableSkewX.h"
#include "..\..\Drawables\DrawableSkewY.h"
#include "..\..\Drawables\DrawableStrokeAntialias.h"
#include "..\..\Drawables\DrawableStrokeColor.h"
#include "..\..\Drawables\DrawableStrokeLineCap.h"
#include "..\..\Drawables\DrawableStrokeLineJoin.h"
#include "..\..\Drawables\DrawableStrokeOpacity.h"
#include "..\..\Drawables\DrawableStrokeWidth.h"
#include "..\..\Drawables\DrawableText.h"
#include "..\..\Drawables\DrawableTextAntialias.h"
#include "..\..\Drawables\DrawableTextDecoration.h"
#include "..\..\Drawables\DrawableTextUnderColor.h"
#include "..\..\Drawables\DrawableTranslation.h"
#include "..\..\Drawables\DrawableViewbox.h"
#include "..\..\Drawables\Paths\PathArcAbs.h"
#include "..\..\Drawables\Paths\PathArcRel.h"
#include "..\..\Drawables\Paths\PathCurvetoAbs.h"
#include "..\..\Drawables\Paths\PathCurvetoRel.h"
#include "..\..\Drawables\Paths\PathLinetoAbs.h"
#include "..\..\Drawables\Paths\PathLinetoHorizontalAbs.h"
#include "..\..\Drawables\Paths\PathLinetoHorizontalRel.h"
#include "..\..\Drawables\Paths\PathLinetoRel.h"
#include "..\..\Drawables\Paths\PathLinetoVerticalAbs.h"
#include "..\..\Drawables\Paths\PathLinetoVerticalRel.h"
#include "..\..\Drawables\Paths\PathMovetoAbs.h"
#include "..\..\Drawables\Paths\PathMovetoRel.h"
#include "..\..\Drawables\Paths\PathQuadraticCurvetoAbs.h"
#include "..\..\Drawables\Paths\PathQuadraticCurvetoRel.h"
#include "..\..\Drawables\Paths\PathSmoothCurvetoAbs.h"
#include "..\..\Drawables\Paths\PathSmoothCurvetoRel.h"
#include "..\..\Drawables\Paths\PathSmoothQuadraticCurvetoAbs.h"
#include "..\..\Drawables\Paths\PathSmoothQuadraticCurvetoRel.h"
#include "..\..\Drawables\Coordinate.h"
#pragma warning (disable: 4100)
namespace GraphicsMagick
{
	void MagickScript::ExecuteImage(XmlElement^ element, MagickImage^ image)
	{
		switch(element->Name[0])
		{
			case 'a':
			{
				switch(element->Name[1])
				{
					case 'd':
					{
						switch(element->Name[2])
						{
							case 'j':
							{
								ExecuteAdjoin(element, image);
								return;
							}
							case 'a':
							{
								ExecuteAdaptiveThreshold(element, image);
								return;
							}
							case 'd':
							{
								switch(element->Name[3])
								{
									case 'N':
									{
										ExecuteAddNoise(element, image);
										return;
									}
									case 'P':
									{
										ExecuteAddProfile(element, image);
										return;
									}
								}
								break;
							}
						}
						break;
					}
					case 'n':
					{
						switch(element->Name[2])
						{
							case 'i':
							{
								switch(element->Name[9])
								{
									case 'D':
									{
										ExecuteAnimationDelay(element, image);
										return;
									}
									case 'I':
									{
										ExecuteAnimationIterations(element, image);
										return;
									}
								}
								break;
							}
							case 't':
							{
								ExecuteAntiAlias(element, image);
								return;
							}
							case 'n':
							{
								ExecuteAnnotate(element, image);
								return;
							}
						}
						break;
					}
				}
				break;
			}
			case 'b':
			{
				switch(element->Name[1])
				{
					case 'a':
					{
						ExecuteBackgroundColor(element, image);
						return;
					}
					case 'o':
					{
						switch(element->Name[2])
						{
							case 'r':
							{
								if (element->Name->Length == 6)
								{
									ExecuteBorder(element, image);
									return;
								}
								if (element->Name->Length == 11)
								{
									ExecuteBorderColor(element, image);
									return;
								}
							}
							case 'x':
							{
								ExecuteBoxColor(element, image);
								return;
							}
						}
						break;
					}
					case 'l':
					{
						ExecuteBlur(element, image);
						return;
					}
				}
				break;
			}
			case 'c':
			{
				switch(element->Name[1])
				{
					case 'l':
					{
						switch(element->Name[2])
						{
							case 'a':
							{
								ExecuteClassType(element, image);
								return;
							}
							case 'i':
							{
								ExecuteClipMask(element, image);
								return;
							}
							case 'o':
							{
								ExecuteClone(element, image);
								return;
							}
						}
						break;
					}
					case 'o':
					{
						switch(element->Name[2])
						{
							case 'l':
							{
								switch(element->Name[5])
								{
									case 'F':
									{
										ExecuteColorFuzz(element, image);
										return;
									}
									case 'M':
									{
										if (element->Name->Length == 8)
										{
											ExecuteColorMap(element, image);
											return;
										}
										if (element->Name->Length == 12)
										{
											ExecuteColorMapSize(element, image);
											return;
										}
									}
									case 'S':
									{
										ExecuteColorSpace(element, image);
										return;
									}
									case 'T':
									{
										ExecuteColorType(element, image);
										return;
									}
									case 'i':
									{
										ExecuteColorize(element, image);
										return;
									}
								}
								break;
							}
							case 'm':
							{
								switch(element->Name[3])
								{
									case 'm':
									{
										ExecuteComment(element, image);
										return;
									}
									case 'p':
									{
										switch(element->Name[4])
										{
											case 'o':
											{
												switch(element->Name[6])
												{
													case 'e':
													{
														ExecuteCompose(element, image);
														return;
													}
													case 'i':
													{
														ExecuteComposite(element, image);
														return;
													}
												}
												break;
											}
											case 'r':
											{
												ExecuteCompressionMethod(element, image);
												return;
											}
										}
										break;
									}
								}
								break;
							}
							case 'n':
							{
								ExecuteContrast(element, image);
								return;
							}
						}
						break;
					}
					case 'd':
					{
						ExecuteCDL(element, image);
						return;
					}
					case 'h':
					{
						switch(element->Name[2])
						{
							case 'a':
							{
								ExecuteCharcoal(element, image);
								return;
							}
							case 'o':
							{
								if (element->Name->Length == 4)
								{
									ExecuteChop(element, image);
									return;
								}
								switch(element->Name[4])
								{
									case 'H':
									{
										ExecuteChopHorizontal(element, image);
										return;
									}
									case 'V':
									{
										ExecuteChopVertical(element, image);
										return;
									}
								}
								break;
							}
							case 'r':
							{
								switch(element->Name[6])
								{
									case 'B':
									{
										ExecuteChromaBluePrimary(element, image);
										return;
									}
									case 'G':
									{
										ExecuteChromaGreenPrimary(element, image);
										return;
									}
									case 'R':
									{
										ExecuteChromaRedPrimary(element, image);
										return;
									}
									case 'W':
									{
										ExecuteChromaWhitePoint(element, image);
										return;
									}
								}
								break;
							}
						}
						break;
					}
					case 'r':
					{
						ExecuteCrop(element, image);
						return;
					}
					case 'y':
					{
						ExecuteCycleColormap(element, image);
						return;
					}
				}
				break;
			}
			case 'd':
			{
				switch(element->Name[1])
				{
					case 'e':
					{
						switch(element->Name[2])
						{
							case 'b':
							{
								ExecuteDebug(element, image);
								return;
							}
							case 'n':
							{
								ExecuteDensity(element, image);
								return;
							}
							case 'p':
							{
								ExecuteDepth(element, image);
								return;
							}
							case 's':
							{
								ExecuteDespeckle(image);
								return;
							}
						}
						break;
					}
					case 'r':
					{
						ExecuteDraw(element, image);
						return;
					}
				}
				break;
			}
			case 'e':
			{
				switch(element->Name[1])
				{
					case 'n':
					{
						switch(element->Name[2])
						{
							case 'd':
							{
								ExecuteEndian(element, image);
								return;
							}
							case 'h':
							{
								ExecuteEnhance(image);
								return;
							}
						}
						break;
					}
					case 'd':
					{
						ExecuteEdge(element, image);
						return;
					}
					case 'm':
					{
						ExecuteEmboss(element, image);
						return;
					}
					case 'q':
					{
						ExecuteEqualize(image);
						return;
					}
					case 'v':
					{
						ExecuteEvaluate(element, image);
						return;
					}
					case 'x':
					{
						ExecuteExtent(element, image);
						return;
					}
				}
				break;
			}
			case 'f':
			{
				switch(element->Name[1])
				{
					case 'i':
					{
						switch(element->Name[3])
						{
							case 'l':
							{
								switch(element->Name[4])
								{
									case 'C':
									{
										ExecuteFillColor(element, image);
										return;
									}
									case 'P':
									{
										ExecuteFillPattern(element, image);
										return;
									}
									case 'R':
									{
										ExecuteFillRule(element, image);
										return;
									}
								}
								break;
							}
							case 't':
							{
								ExecuteFilterType(element, image);
								return;
							}
						}
						break;
					}
					case 'l':
					{
						switch(element->Name[2])
						{
							case 'a':
							{
								ExecuteFlashPixView(element, image);
								return;
							}
							case 'i':
							{
								ExecuteFlip(image);
								return;
							}
							case 'o':
							{
								switch(element->Name[3])
								{
									case 'o':
									{
										ExecuteFloodFill(element, image);
										return;
									}
									case 'p':
									{
										ExecuteFlop(image);
										return;
									}
								}
								break;
							}
						}
						break;
					}
					case 'o':
					{
						switch(element->Name[2])
						{
							case 'n':
							{
								if (element->Name->Length == 4)
								{
									ExecuteFont(element, image);
									return;
								}
								if (element->Name->Length == 13)
								{
									ExecuteFontPointsize(element, image);
									return;
								}
							}
							case 'r':
							{
								ExecuteFormat(element, image);
								return;
							}
						}
						break;
					}
					case 'r':
					{
						ExecuteFrame(element, image);
						return;
					}
				}
				break;
			}
			case 'g':
			{
				switch(element->Name[1])
				{
					case 'i':
					{
						ExecuteGifDisposeMethod(element, image);
						return;
					}
					case 'a':
					{
						switch(element->Name[2])
						{
							case 'm':
							{
								ExecuteGamma(element, image);
								return;
							}
							case 'u':
							{
								ExecuteGaussianBlur(element, image);
								return;
							}
						}
						break;
					}
				}
				break;
			}
			case 'h':
			{
				switch(element->Name[2])
				{
					case 's':
					{
						ExecuteHasAlpha(element, image);
						return;
					}
					case 'l':
					{
						ExecuteHaldClut(element, image);
						return;
					}
				}
				break;
			}
			case 'i':
			{
				switch(element->Name[1])
				{
					case 'n':
					{
						ExecuteInterlace(element, image);
						return;
					}
					case 'm':
					{
						ExecuteImplode(element, image);
						return;
					}
				}
				break;
			}
			case 'l':
			{
				switch(element->Name[1])
				{
					case 'a':
					{
						ExecuteLabel(element, image);
						return;
					}
					case 'e':
					{
						ExecuteLevel(element, image);
						return;
					}
					case 'o':
					{
						ExecuteLower(element, image);
						return;
					}
				}
				break;
			}
			case 'm':
			{
				switch(element->Name[1])
				{
					case 'a':
					{
						switch(element->Name[2])
						{
							case 't':
							{
								ExecuteMatteColor(element, image);
								return;
							}
							case 'g':
							{
								ExecuteMagnify(image);
								return;
							}
						}
						break;
					}
					case 'e':
					{
						ExecuteMedianFilter(element, image);
						return;
					}
					case 'i':
					{
						ExecuteMinify(image);
						return;
					}
					case 'o':
					{
						switch(element->Name[2])
						{
							case 'd':
							{
								ExecuteModulate(element, image);
								return;
							}
							case 't':
							{
								ExecuteMotionBlur(element, image);
								return;
							}
						}
						break;
					}
				}
				break;
			}
			case 'o':
			{
				switch(element->Name[1])
				{
					case 'r':
					{
						ExecuteOrientation(element, image);
						return;
					}
					case 'i':
					{
						ExecuteOilPaint(element, image);
						return;
					}
					case 'p':
					{
						ExecuteOpaque(element, image);
						return;
					}
				}
				break;
			}
			case 'p':
			{
				switch(element->Name[1])
				{
					case 'a':
					{
						ExecutePage(element, image);
						return;
					}
					case 'r':
					{
						ExecutePreserveColorType(image);
						return;
					}
				}
				break;
			}
			case 'q':
			{
				switch(element->Name[3])
				{
					case 'l':
					{
						ExecuteQuality(element, image);
						return;
					}
					case 'n':
					{
						ExecuteQuantize(element, image);
						return;
					}
				}
				break;
			}
			case 'r':
			{
				switch(element->Name[1])
				{
					case 'e':
					{
						switch(element->Name[2])
						{
							case 'n':
							{
								ExecuteRenderingIntent(element, image);
								return;
							}
							case 's':
							{
								switch(element->Name[3])
								{
									case 'o':
									{
										ExecuteResolutionUnits(element, image);
										return;
									}
									case 'i':
									{
										ExecuteResize(element, image);
										return;
									}
								}
								break;
							}
							case 'd':
							{
								ExecuteReduceNoise(element, image);
								return;
							}
							case 'm':
							{
								switch(element->Name[6])
								{
									case 'D':
									{
										ExecuteRemoveDefine(element, image);
										return;
									}
									case 'P':
									{
										ExecuteRemoveProfile(element, image);
										return;
									}
								}
								break;
							}
							case 'P':
							{
								ExecuteRePage(image);
								return;
							}
						}
						break;
					}
					case 'a':
					{
						switch(element->Name[2])
						{
							case 'i':
							{
								ExecuteRaise(element, image);
								return;
							}
							case 'n':
							{
								ExecuteRandomThreshold(element, image);
								return;
							}
						}
						break;
					}
					case 'o':
					{
						switch(element->Name[2])
						{
							case 'l':
							{
								ExecuteRoll(element, image);
								return;
							}
							case 't':
							{
								ExecuteRotate(element, image);
								return;
							}
						}
						break;
					}
				}
				break;
			}
			case 's':
			{
				switch(element->Name[1])
				{
					case 't':
					{
						switch(element->Name[2])
						{
							case 'r':
							{
								switch(element->Name[3])
								{
									case 'o':
									{
										switch(element->Name[6])
										{
											case 'A':
											{
												ExecuteStrokeAntiAlias(element, image);
												return;
											}
											case 'C':
											{
												ExecuteStrokeColor(element, image);
												return;
											}
											case 'D':
											{
												switch(element->Name[10])
												{
													case 'A':
													{
														ExecuteStrokeDashArray(element, image);
														return;
													}
													case 'O':
													{
														ExecuteStrokeDashOffset(element, image);
														return;
													}
												}
												break;
											}
											case 'L':
											{
												switch(element->Name[10])
												{
													case 'C':
													{
														ExecuteStrokeLineCap(element, image);
														return;
													}
													case 'J':
													{
														ExecuteStrokeLineJoin(element, image);
														return;
													}
												}
												break;
											}
											case 'M':
											{
												ExecuteStrokeMiterLimit(element, image);
												return;
											}
											case 'P':
											{
												ExecuteStrokePattern(element, image);
												return;
											}
											case 'W':
											{
												ExecuteStrokeWidth(element, image);
												return;
											}
										}
										break;
									}
									case 'i':
									{
										ExecuteStrip(image);
										return;
									}
								}
								break;
							}
							case 'e':
							{
								switch(element->Name[3])
								{
									case 'g':
									{
										ExecuteStegano(element, image);
										return;
									}
									case 'r':
									{
										ExecuteStereo(element, image);
										return;
									}
								}
								break;
							}
						}
						break;
					}
					case 'a':
					{
						ExecuteSample(element, image);
						return;
					}
					case 'c':
					{
						ExecuteScale(element, image);
						return;
					}
					case 'e':
					{
						switch(element->Name[2])
						{
							case 'g':
							{
								ExecuteSegment(element, image);
								return;
							}
							case 't':
							{
								switch(element->Name[3])
								{
									case 'A':
									{
										ExecuteSetAttribute(element, image);
										return;
									}
									case 'D':
									{
										ExecuteSetDefine(element, image);
										return;
									}
								}
								break;
							}
						}
						break;
					}
					case 'h':
					{
						switch(element->Name[2])
						{
							case 'a':
							{
								switch(element->Name[3])
								{
									case 'd':
									{
										ExecuteShade(element, image);
										return;
									}
									case 'r':
									{
										ExecuteSharpen(element, image);
										return;
									}
									case 'v':
									{
										ExecuteShave(element, image);
										return;
									}
								}
								break;
							}
							case 'e':
							{
								ExecuteShear(element, image);
								return;
							}
						}
						break;
					}
					case 'o':
					{
						ExecuteSolarize(element, image);
						return;
					}
					case 'p':
					{
						ExecuteSpread(element, image);
						return;
					}
					case 'w':
					{
						ExecuteSwirl(element, image);
						return;
					}
				}
				break;
			}
			case 't':
			{
				switch(element->Name[1])
				{
					case 'e':
					{
						switch(element->Name[4])
						{
							case 'E':
							{
								ExecuteTextEncoding(element, image);
								return;
							}
							case 'u':
							{
								ExecuteTexture(element, image);
								return;
							}
						}
						break;
					}
					case 'i':
					{
						if (element->Name->Length == 4)
						{
							ExecuteTile(element, image);
							return;
						}
						if (element->Name->Length == 8)
						{
							ExecuteTileName(element, image);
							return;
						}
					}
					case 'h':
					{
						switch(element->Name[2])
						{
							case 'r':
							{
								ExecuteThreshold(element, image);
								return;
							}
							case 'u':
							{
								ExecuteThumbnail(element, image);
								return;
							}
						}
						break;
					}
					case 'r':
					{
						switch(element->Name[2])
						{
							case 'a':
							{
								switch(element->Name[5])
								{
									case 'f':
									{
										if (element->Name->Length == 9)
										{
											ExecuteTransform(element, image);
											return;
										}
										switch(element->Name[9])
										{
											case 'O':
											{
												ExecuteTransformOrigin(element, image);
												return;
											}
											case 'R':
											{
												switch(element->Name[10])
												{
													case 'e':
													{
														ExecuteTransformReset(image);
														return;
													}
													case 'o':
													{
														ExecuteTransformRotation(element, image);
														return;
													}
												}
												break;
											}
											case 'S':
											{
												switch(element->Name[10])
												{
													case 'c':
													{
														ExecuteTransformScale(element, image);
														return;
													}
													case 'k':
													{
														switch(element->Name[13])
														{
															case 'X':
															{
																ExecuteTransformSkewX(element, image);
																return;
															}
															case 'Y':
															{
																ExecuteTransformSkewY(element, image);
																return;
															}
														}
														break;
													}
												}
												break;
											}
										}
										break;
									}
									case 'p':
									{
										ExecuteTransparent(element, image);
										return;
									}
								}
								break;
							}
							case 'i':
							{
								ExecuteTrim(image);
								return;
							}
						}
						break;
					}
				}
				break;
			}
			case 'v':
			{
				ExecuteVerbose(element, image);
				return;
			}
			case 'n':
			{
				switch(element->Name[1])
				{
					case 'e':
					{
						ExecuteNegate(element, image);
						return;
					}
					case 'o':
					{
						ExecuteNormalize(image);
						return;
					}
				}
				break;
			}
			case 'u':
			{
				ExecuteUnsharpmask(element, image);
				return;
			}
			case 'w':
			{
				switch(element->Name[1])
				{
					case 'a':
					{
						ExecuteWave(element, image);
						return;
					}
					case 'r':
					{
						ExecuteWrite(element, image);
						return;
					}
				}
				break;
			}
			case 'z':
			{
				ExecuteZoom(element, image);
				return;
			}
		}
		throw gcnew NotImplementedException(element->Name);
	}
	void MagickScript::ExecuteAdjoin(XmlElement^ element, MagickImage^ image)
	{
		image->Adjoin = _Variables->GetValue<bool>(element, "value");
	}
	void MagickScript::ExecuteAnimationDelay(XmlElement^ element, MagickImage^ image)
	{
		image->AnimationDelay = _Variables->GetValue<int>(element, "value");
	}
	void MagickScript::ExecuteAnimationIterations(XmlElement^ element, MagickImage^ image)
	{
		image->AnimationIterations = _Variables->GetValue<int>(element, "value");
	}
	void MagickScript::ExecuteAntiAlias(XmlElement^ element, MagickImage^ image)
	{
		image->AntiAlias = _Variables->GetValue<bool>(element, "value");
	}
	void MagickScript::ExecuteBackgroundColor(XmlElement^ element, MagickImage^ image)
	{
		image->BackgroundColor = _Variables->GetValue<MagickColor^>(element, "value");
	}
	void MagickScript::ExecuteBorderColor(XmlElement^ element, MagickImage^ image)
	{
		image->BorderColor = _Variables->GetValue<MagickColor^>(element, "value");
	}
	void MagickScript::ExecuteBoxColor(XmlElement^ element, MagickImage^ image)
	{
		image->BoxColor = _Variables->GetValue<MagickColor^>(element, "value");
	}
	void MagickScript::ExecuteClassType(XmlElement^ element, MagickImage^ image)
	{
		image->ClassType = _Variables->GetValue<ClassType>(element, "value");
	}
	void MagickScript::ExecuteClipMask(XmlElement^ element, MagickImage^ image)
	{
		image->ClipMask = CreateMagickImage(element);
	}
	void MagickScript::ExecuteColorFuzz(XmlElement^ element, MagickImage^ image)
	{
		image->ColorFuzz = _Variables->GetValue<Percentage>(element, "value");
	}
	void MagickScript::ExecuteColorMapSize(XmlElement^ element, MagickImage^ image)
	{
		image->ColorMapSize = _Variables->GetValue<int>(element, "value");
	}
	void MagickScript::ExecuteColorSpace(XmlElement^ element, MagickImage^ image)
	{
		image->ColorSpace = _Variables->GetValue<ColorSpace>(element, "value");
	}
	void MagickScript::ExecuteColorType(XmlElement^ element, MagickImage^ image)
	{
		image->ColorType = _Variables->GetValue<ColorType>(element, "value");
	}
	void MagickScript::ExecuteComment(XmlElement^ element, MagickImage^ image)
	{
		image->Comment = _Variables->GetValue<String^>(element, "value");
	}
	void MagickScript::ExecuteCompose(XmlElement^ element, MagickImage^ image)
	{
		image->Compose = _Variables->GetValue<CompositeOperator>(element, "value");
	}
	void MagickScript::ExecuteCompressionMethod(XmlElement^ element, MagickImage^ image)
	{
		image->CompressionMethod = _Variables->GetValue<CompressionMethod>(element, "value");
	}
	void MagickScript::ExecuteDebug(XmlElement^ element, MagickImage^ image)
	{
		image->Debug = _Variables->GetValue<bool>(element, "value");
	}
	void MagickScript::ExecuteDensity(XmlElement^ element, MagickImage^ image)
	{
		image->Density = _Variables->GetValue<MagickGeometry^>(element, "value");
	}
	void MagickScript::ExecuteDepth(XmlElement^ element, MagickImage^ image)
	{
		image->Depth = _Variables->GetValue<int>(element, "value");
	}
	void MagickScript::ExecuteEndian(XmlElement^ element, MagickImage^ image)
	{
		image->Endian = _Variables->GetValue<Endian>(element, "value");
	}
	void MagickScript::ExecuteFillColor(XmlElement^ element, MagickImage^ image)
	{
		image->FillColor = _Variables->GetValue<MagickColor^>(element, "value");
	}
	void MagickScript::ExecuteFillPattern(XmlElement^ element, MagickImage^ image)
	{
		image->FillPattern = CreateMagickImage(element);
	}
	void MagickScript::ExecuteFillRule(XmlElement^ element, MagickImage^ image)
	{
		image->FillRule = _Variables->GetValue<FillRule>(element, "value");
	}
	void MagickScript::ExecuteFilterType(XmlElement^ element, MagickImage^ image)
	{
		image->FilterType = _Variables->GetValue<FilterType>(element, "value");
	}
	void MagickScript::ExecuteFlashPixView(XmlElement^ element, MagickImage^ image)
	{
		image->FlashPixView = _Variables->GetValue<String^>(element, "value");
	}
	void MagickScript::ExecuteFont(XmlElement^ element, MagickImage^ image)
	{
		image->Font = _Variables->GetValue<String^>(element, "value");
	}
	void MagickScript::ExecuteFontPointsize(XmlElement^ element, MagickImage^ image)
	{
		image->FontPointsize = _Variables->GetValue<double>(element, "value");
	}
	void MagickScript::ExecuteFormat(XmlElement^ element, MagickImage^ image)
	{
		image->Format = _Variables->GetValue<MagickFormat>(element, "value");
	}
	void MagickScript::ExecuteGifDisposeMethod(XmlElement^ element, MagickImage^ image)
	{
		image->GifDisposeMethod = _Variables->GetValue<GifDisposeMethod>(element, "value");
	}
	void MagickScript::ExecuteHasAlpha(XmlElement^ element, MagickImage^ image)
	{
		image->HasAlpha = _Variables->GetValue<bool>(element, "value");
	}
	void MagickScript::ExecuteInterlace(XmlElement^ element, MagickImage^ image)
	{
		image->Interlace = _Variables->GetValue<Interlace>(element, "value");
	}
	void MagickScript::ExecuteLabel(XmlElement^ element, MagickImage^ image)
	{
		image->Label = _Variables->GetValue<String^>(element, "value");
	}
	void MagickScript::ExecuteMatteColor(XmlElement^ element, MagickImage^ image)
	{
		image->MatteColor = _Variables->GetValue<MagickColor^>(element, "value");
	}
	void MagickScript::ExecuteOrientation(XmlElement^ element, MagickImage^ image)
	{
		image->Orientation = _Variables->GetValue<OrientationType>(element, "value");
	}
	void MagickScript::ExecutePage(XmlElement^ element, MagickImage^ image)
	{
		image->Page = _Variables->GetValue<MagickGeometry^>(element, "value");
	}
	void MagickScript::ExecuteQuality(XmlElement^ element, MagickImage^ image)
	{
		image->Quality = _Variables->GetValue<int>(element, "value");
	}
	void MagickScript::ExecuteRenderingIntent(XmlElement^ element, MagickImage^ image)
	{
		image->RenderingIntent = _Variables->GetValue<RenderingIntent>(element, "value");
	}
	void MagickScript::ExecuteResolutionUnits(XmlElement^ element, MagickImage^ image)
	{
		image->ResolutionUnits = _Variables->GetValue<Resolution>(element, "value");
	}
	void MagickScript::ExecuteStrokeAntiAlias(XmlElement^ element, MagickImage^ image)
	{
		image->StrokeAntiAlias = _Variables->GetValue<bool>(element, "value");
	}
	void MagickScript::ExecuteStrokeColor(XmlElement^ element, MagickImage^ image)
	{
		image->StrokeColor = _Variables->GetValue<MagickColor^>(element, "value");
	}
	void MagickScript::ExecuteStrokeDashArray(XmlElement^ element, MagickImage^ image)
	{
		image->StrokeDashArray = _Variables->GetDoubleArray(element);
	}
	void MagickScript::ExecuteStrokeDashOffset(XmlElement^ element, MagickImage^ image)
	{
		image->StrokeDashOffset = _Variables->GetValue<double>(element, "value");
	}
	void MagickScript::ExecuteStrokeLineCap(XmlElement^ element, MagickImage^ image)
	{
		image->StrokeLineCap = _Variables->GetValue<LineCap>(element, "value");
	}
	void MagickScript::ExecuteStrokeLineJoin(XmlElement^ element, MagickImage^ image)
	{
		image->StrokeLineJoin = _Variables->GetValue<LineJoin>(element, "value");
	}
	void MagickScript::ExecuteStrokeMiterLimit(XmlElement^ element, MagickImage^ image)
	{
		image->StrokeMiterLimit = _Variables->GetValue<int>(element, "value");
	}
	void MagickScript::ExecuteStrokePattern(XmlElement^ element, MagickImage^ image)
	{
		image->StrokePattern = CreateMagickImage(element);
	}
	void MagickScript::ExecuteStrokeWidth(XmlElement^ element, MagickImage^ image)
	{
		image->StrokeWidth = _Variables->GetValue<double>(element, "value");
	}
	void MagickScript::ExecuteTextEncoding(XmlElement^ element, MagickImage^ image)
	{
		image->TextEncoding = _Variables->GetValue<Encoding^>(element, "value");
	}
	void MagickScript::ExecuteTileName(XmlElement^ element, MagickImage^ image)
	{
		image->TileName = _Variables->GetValue<String^>(element, "value");
	}
	void MagickScript::ExecuteVerbose(XmlElement^ element, MagickImage^ image)
	{
		image->Verbose = _Variables->GetValue<bool>(element, "value");
	}
	void MagickScript::ExecuteAdaptiveThreshold(XmlElement^ element, MagickImage^ image)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			if (attribute->Name == "bias")
				arguments["bias"] = _Variables->GetValue<Percentage>(attribute);
			else if (attribute->Name == "height")
				arguments["height"] = _Variables->GetValue<int>(attribute);
			else if (attribute->Name == "width")
				arguments["width"] = _Variables->GetValue<int>(attribute);
		}
		if (OnlyContains(arguments, "width", "height"))
			image->AdaptiveThreshold((int)arguments["width"], (int)arguments["height"]);
		else if (OnlyContains(arguments, "width", "height", "bias"))
			image->AdaptiveThreshold((int)arguments["width"], (int)arguments["height"], (Percentage)arguments["bias"]);
		else if (OnlyContains(arguments, "width", "height", "bias"))
			image->AdaptiveThreshold((int)arguments["width"], (int)arguments["height"], (double)arguments["bias"]);
		else
			throw gcnew ArgumentException("Invalid argument combination for 'adaptiveThreshold', allowed combinations are: [width, height] [width, height, bias] [width, height, bias]");
	}
	void MagickScript::ExecuteAddNoise(XmlElement^ element, MagickImage^ image)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			if (attribute->Name == "channels")
				arguments["channels"] = _Variables->GetValue<Channels>(attribute);
			else if (attribute->Name == "noiseType")
				arguments["noiseType"] = _Variables->GetValue<NoiseType>(attribute);
		}
		if (OnlyContains(arguments, "noiseType"))
			image->AddNoise((NoiseType)arguments["noiseType"]);
		else if (OnlyContains(arguments, "noiseType", "channels"))
			image->AddNoise((NoiseType)arguments["noiseType"], (Channels)arguments["channels"]);
		else
			throw gcnew ArgumentException("Invalid argument combination for 'addNoise', allowed combinations are: [noiseType] [noiseType, channels]");
	}
	void MagickScript::ExecuteAddProfile(XmlElement^ element, MagickImage^ image)
	{
		ImageProfile^ profile_ = CreateProfile(element);
		image->AddProfile(profile_);
	}
	void MagickScript::ExecuteAnnotate(XmlElement^ element, MagickImage^ image)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			if (attribute->Name == "boundingArea")
				arguments["boundingArea"] = _Variables->GetValue<MagickGeometry^>(attribute);
			else if (attribute->Name == "degrees")
				arguments["degrees"] = _Variables->GetValue<double>(attribute);
			else if (attribute->Name == "gravity")
				arguments["gravity"] = _Variables->GetValue<Gravity>(attribute);
			else if (attribute->Name == "text")
				arguments["text"] = _Variables->GetValue<String^>(attribute);
		}
		if (OnlyContains(arguments, "text", "boundingArea"))
			image->Annotate((String^)arguments["text"], (MagickGeometry^)arguments["boundingArea"]);
		else if (OnlyContains(arguments, "text", "boundingArea", "gravity"))
			image->Annotate((String^)arguments["text"], (MagickGeometry^)arguments["boundingArea"], (Gravity)arguments["gravity"]);
		else if (OnlyContains(arguments, "text", "boundingArea", "gravity", "degrees"))
			image->Annotate((String^)arguments["text"], (MagickGeometry^)arguments["boundingArea"], (Gravity)arguments["gravity"], (double)arguments["degrees"]);
		else if (OnlyContains(arguments, "text", "gravity"))
			image->Annotate((String^)arguments["text"], (Gravity)arguments["gravity"]);
		else
			throw gcnew ArgumentException("Invalid argument combination for 'annotate', allowed combinations are: [text, boundingArea] [text, boundingArea, gravity] [text, boundingArea, gravity, degrees] [text, gravity]");
	}
	void MagickScript::ExecuteBlur(XmlElement^ element, MagickImage^ image)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			if (attribute->Name == "channels")
				arguments["channels"] = _Variables->GetValue<Channels>(attribute);
			else if (attribute->Name == "radius")
				arguments["radius"] = _Variables->GetValue<double>(attribute);
			else if (attribute->Name == "sigma")
				arguments["sigma"] = _Variables->GetValue<double>(attribute);
		}
		if (arguments->Count == 0)
			image->Blur();
		else if (OnlyContains(arguments, "channels"))
			image->Blur((Channels)arguments["channels"]);
		else if (OnlyContains(arguments, "radius", "sigma"))
			image->Blur((double)arguments["radius"], (double)arguments["sigma"]);
		else if (OnlyContains(arguments, "radius", "sigma", "channels"))
			image->Blur((double)arguments["radius"], (double)arguments["sigma"], (Channels)arguments["channels"]);
		else
			throw gcnew ArgumentException("Invalid argument combination for 'blur', allowed combinations are: [] [channels] [radius, sigma] [radius, sigma, channels]");
	}
	void MagickScript::ExecuteBorder(XmlElement^ element, MagickImage^ image)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			arguments[attribute->Name] = _Variables->GetValue<int>(attribute);
		}
		if (OnlyContains(arguments, "size"))
			image->Border((int)arguments["size"]);
		else if (OnlyContains(arguments, "width", "height"))
			image->Border((int)arguments["width"], (int)arguments["height"]);
		else
			throw gcnew ArgumentException("Invalid argument combination for 'border', allowed combinations are: [size] [width, height]");
	}
	void MagickScript::ExecuteCDL(XmlElement^ element, MagickImage^ image)
	{
		String^ fileName_ = _Variables->GetValue<String^>(element, "fileName");
		image->CDL(fileName_);
	}
	void MagickScript::ExecuteCharcoal(XmlElement^ element, MagickImage^ image)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			arguments[attribute->Name] = _Variables->GetValue<double>(attribute);
		}
		if (arguments->Count == 0)
			image->Charcoal();
		else if (OnlyContains(arguments, "radius", "sigma"))
			image->Charcoal((double)arguments["radius"], (double)arguments["sigma"]);
		else
			throw gcnew ArgumentException("Invalid argument combination for 'charcoal', allowed combinations are: [] [radius, sigma]");
	}
	void MagickScript::ExecuteChop(XmlElement^ element, MagickImage^ image)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			if (attribute->Name == "geometry")
				arguments["geometry"] = _Variables->GetValue<MagickGeometry^>(attribute);
			else if (attribute->Name == "height")
				arguments["height"] = _Variables->GetValue<int>(attribute);
			else if (attribute->Name == "width")
				arguments["width"] = _Variables->GetValue<int>(attribute);
			else if (attribute->Name == "xOffset")
				arguments["xOffset"] = _Variables->GetValue<int>(attribute);
			else if (attribute->Name == "yOffset")
				arguments["yOffset"] = _Variables->GetValue<int>(attribute);
		}
		if (OnlyContains(arguments, "geometry"))
			image->Chop((MagickGeometry^)arguments["geometry"]);
		else if (OnlyContains(arguments, "xOffset", "width", "yOffset", "height"))
			image->Chop((int)arguments["xOffset"], (int)arguments["width"], (int)arguments["yOffset"], (int)arguments["height"]);
		else
			throw gcnew ArgumentException("Invalid argument combination for 'chop', allowed combinations are: [geometry] [xOffset, width, yOffset, height]");
	}
	void MagickScript::ExecuteChopHorizontal(XmlElement^ element, MagickImage^ image)
	{
		int offset_ = _Variables->GetValue<int>(element, "offset");
		int width_ = _Variables->GetValue<int>(element, "width");
		image->ChopHorizontal(offset_, width_);
	}
	void MagickScript::ExecuteChopVertical(XmlElement^ element, MagickImage^ image)
	{
		int offset_ = _Variables->GetValue<int>(element, "offset");
		int height_ = _Variables->GetValue<int>(element, "height");
		image->ChopVertical(offset_, height_);
	}
	void MagickScript::ExecuteChromaBluePrimary(XmlElement^ element, MagickImage^ image)
	{
		double x_ = _Variables->GetValue<double>(element, "x");
		double y_ = _Variables->GetValue<double>(element, "y");
		image->ChromaBluePrimary(x_, y_);
	}
	void MagickScript::ExecuteChromaGreenPrimary(XmlElement^ element, MagickImage^ image)
	{
		double x_ = _Variables->GetValue<double>(element, "x");
		double y_ = _Variables->GetValue<double>(element, "y");
		image->ChromaGreenPrimary(x_, y_);
	}
	void MagickScript::ExecuteChromaRedPrimary(XmlElement^ element, MagickImage^ image)
	{
		double x_ = _Variables->GetValue<double>(element, "x");
		double y_ = _Variables->GetValue<double>(element, "y");
		image->ChromaRedPrimary(x_, y_);
	}
	void MagickScript::ExecuteChromaWhitePoint(XmlElement^ element, MagickImage^ image)
	{
		double x_ = _Variables->GetValue<double>(element, "x");
		double y_ = _Variables->GetValue<double>(element, "y");
		image->ChromaWhitePoint(x_, y_);
	}
	void MagickScript::ExecuteColorize(XmlElement^ element, MagickImage^ image)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			if (attribute->Name == "alpha")
				arguments["alpha"] = _Variables->GetValue<Percentage>(attribute);
			else if (attribute->Name == "alphaBlue")
				arguments["alphaBlue"] = _Variables->GetValue<Percentage>(attribute);
			else if (attribute->Name == "alphaGreen")
				arguments["alphaGreen"] = _Variables->GetValue<Percentage>(attribute);
			else if (attribute->Name == "alphaRed")
				arguments["alphaRed"] = _Variables->GetValue<Percentage>(attribute);
			else if (attribute->Name == "color")
				arguments["color"] = _Variables->GetValue<MagickColor^>(attribute);
		}
		if (OnlyContains(arguments, "color", "alpha"))
			image->Colorize((MagickColor^)arguments["color"], (Percentage)arguments["alpha"]);
		else if (OnlyContains(arguments, "color", "alphaRed", "alphaGreen", "alphaBlue"))
			image->Colorize((MagickColor^)arguments["color"], (Percentage)arguments["alphaRed"], (Percentage)arguments["alphaGreen"], (Percentage)arguments["alphaBlue"]);
		else
			throw gcnew ArgumentException("Invalid argument combination for 'colorize', allowed combinations are: [color, alpha] [color, alphaRed, alphaGreen, alphaBlue]");
	}
	void MagickScript::ExecuteColorMap(XmlElement^ element, MagickImage^ image)
	{
		int index_ = _Variables->GetValue<int>(element, "index");
		MagickColor^ color_ = _Variables->GetValue<MagickColor^>(element, "color");
		image->ColorMap(index_, color_);
	}
	void MagickScript::ExecuteComposite(XmlElement^ element, MagickImage^ image)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			if (attribute->Name == "compose")
				arguments["compose"] = _Variables->GetValue<CompositeOperator>(attribute);
			else if (attribute->Name == "gravity")
				arguments["gravity"] = _Variables->GetValue<Gravity>(attribute);
			else if (attribute->Name == "offset")
				arguments["offset"] = _Variables->GetValue<MagickGeometry^>(attribute);
			else if (attribute->Name == "x")
				arguments["x"] = _Variables->GetValue<int>(attribute);
			else if (attribute->Name == "y")
				arguments["y"] = _Variables->GetValue<int>(attribute);
		}
		for each(XmlElement^ elem in element->SelectNodes("*"))
		{
			arguments[elem->Name] = CreateMagickImage(elem);
		}
		if (OnlyContains(arguments, "image", "compose"))
			image->Composite((MagickImage^)arguments["image"], (CompositeOperator)arguments["compose"]);
		else if (OnlyContains(arguments, "image", "gravity"))
			image->Composite((MagickImage^)arguments["image"], (Gravity)arguments["gravity"]);
		else if (OnlyContains(arguments, "image", "gravity", "compose"))
			image->Composite((MagickImage^)arguments["image"], (Gravity)arguments["gravity"], (CompositeOperator)arguments["compose"]);
		else if (OnlyContains(arguments, "image", "offset"))
			image->Composite((MagickImage^)arguments["image"], (MagickGeometry^)arguments["offset"]);
		else if (OnlyContains(arguments, "image", "offset", "compose"))
			image->Composite((MagickImage^)arguments["image"], (MagickGeometry^)arguments["offset"], (CompositeOperator)arguments["compose"]);
		else if (OnlyContains(arguments, "image", "x", "y"))
			image->Composite((MagickImage^)arguments["image"], (int)arguments["x"], (int)arguments["y"]);
		else if (OnlyContains(arguments, "image", "x", "y", "compose"))
			image->Composite((MagickImage^)arguments["image"], (int)arguments["x"], (int)arguments["y"], (CompositeOperator)arguments["compose"]);
		else
			throw gcnew ArgumentException("Invalid argument combination for 'composite', allowed combinations are: [image, compose] [image, gravity] [image, gravity, compose] [image, offset] [image, offset, compose] [image, x, y] [image, x, y, compose]");
	}
	void MagickScript::ExecuteContrast(XmlElement^ element, MagickImage^ image)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			arguments[attribute->Name] = _Variables->GetValue<bool>(attribute);
		}
		if (arguments->Count == 0)
			image->Contrast();
		else if (OnlyContains(arguments, "enhance"))
			image->Contrast((bool)arguments["enhance"]);
		else
			throw gcnew ArgumentException("Invalid argument combination for 'contrast', allowed combinations are: [] [enhance]");
	}
	void MagickScript::ExecuteCrop(XmlElement^ element, MagickImage^ image)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			if (attribute->Name == "geometry")
				arguments["geometry"] = _Variables->GetValue<MagickGeometry^>(attribute);
			else if (attribute->Name == "gravity")
				arguments["gravity"] = _Variables->GetValue<Gravity>(attribute);
			else if (attribute->Name == "height")
				arguments["height"] = _Variables->GetValue<int>(attribute);
			else if (attribute->Name == "width")
				arguments["width"] = _Variables->GetValue<int>(attribute);
		}
		if (OnlyContains(arguments, "geometry"))
			image->Crop((MagickGeometry^)arguments["geometry"]);
		else if (OnlyContains(arguments, "width", "height"))
			image->Crop((int)arguments["width"], (int)arguments["height"]);
		else if (OnlyContains(arguments, "width", "height", "gravity"))
			image->Crop((int)arguments["width"], (int)arguments["height"], (Gravity)arguments["gravity"]);
		else
			throw gcnew ArgumentException("Invalid argument combination for 'crop', allowed combinations are: [geometry] [width, height] [width, height, gravity]");
	}
	void MagickScript::ExecuteCycleColormap(XmlElement^ element, MagickImage^ image)
	{
		int amount_ = _Variables->GetValue<int>(element, "amount");
		image->CycleColormap(amount_);
	}
	void MagickScript::ExecuteDespeckle(MagickImage^ image)
	{
		image->Despeckle();
	}
	void MagickScript::ExecuteEdge(XmlElement^ element, MagickImage^ image)
	{
		double radius_ = _Variables->GetValue<double>(element, "radius");
		image->Edge(radius_);
	}
	void MagickScript::ExecuteEmboss(XmlElement^ element, MagickImage^ image)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			arguments[attribute->Name] = _Variables->GetValue<double>(attribute);
		}
		if (arguments->Count == 0)
			image->Emboss();
		else if (OnlyContains(arguments, "radius", "sigma"))
			image->Emboss((double)arguments["radius"], (double)arguments["sigma"]);
		else
			throw gcnew ArgumentException("Invalid argument combination for 'emboss', allowed combinations are: [] [radius, sigma]");
	}
	void MagickScript::ExecuteEnhance(MagickImage^ image)
	{
		image->Enhance();
	}
	void MagickScript::ExecuteEqualize(MagickImage^ image)
	{
		image->Equalize();
	}
	void MagickScript::ExecuteEvaluate(XmlElement^ element, MagickImage^ image)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			if (attribute->Name == "channels")
				arguments["channels"] = _Variables->GetValue<Channels>(attribute);
			else if (attribute->Name == "evaluateOperator")
				arguments["evaluateOperator"] = _Variables->GetValue<QuantumOperator>(attribute);
			else if (attribute->Name == "geometry")
				arguments["geometry"] = _Variables->GetValue<MagickGeometry^>(attribute);
			else if (attribute->Name == "value")
				arguments["value"] = _Variables->GetValue<double>(attribute);
		}
		if (OnlyContains(arguments, "channels", "evaluateOperator", "value"))
			image->Evaluate((Channels)arguments["channels"], (QuantumOperator)arguments["evaluateOperator"], (double)arguments["value"]);
		else if (OnlyContains(arguments, "channels", "geometry", "evaluateOperator", "value"))
			image->Evaluate((Channels)arguments["channels"], (MagickGeometry^)arguments["geometry"], (QuantumOperator)arguments["evaluateOperator"], (double)arguments["value"]);
		else
			throw gcnew ArgumentException("Invalid argument combination for 'evaluate', allowed combinations are: [channels, evaluateOperator, value] [channels, geometry, evaluateOperator, value]");
	}
	void MagickScript::ExecuteExtent(XmlElement^ element, MagickImage^ image)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			if (attribute->Name == "backgroundColor")
				arguments["backgroundColor"] = _Variables->GetValue<MagickColor^>(attribute);
			else if (attribute->Name == "geometry")
				arguments["geometry"] = _Variables->GetValue<MagickGeometry^>(attribute);
			else if (attribute->Name == "gravity")
				arguments["gravity"] = _Variables->GetValue<Gravity>(attribute);
			else if (attribute->Name == "height")
				arguments["height"] = _Variables->GetValue<int>(attribute);
			else if (attribute->Name == "width")
				arguments["width"] = _Variables->GetValue<int>(attribute);
		}
		if (OnlyContains(arguments, "geometry"))
			image->Extent((MagickGeometry^)arguments["geometry"]);
		else if (OnlyContains(arguments, "geometry", "backgroundColor"))
			image->Extent((MagickGeometry^)arguments["geometry"], (MagickColor^)arguments["backgroundColor"]);
		else if (OnlyContains(arguments, "geometry", "gravity"))
			image->Extent((MagickGeometry^)arguments["geometry"], (Gravity)arguments["gravity"]);
		else if (OnlyContains(arguments, "geometry", "gravity", "backgroundColor"))
			image->Extent((MagickGeometry^)arguments["geometry"], (Gravity)arguments["gravity"], (MagickColor^)arguments["backgroundColor"]);
		else if (OnlyContains(arguments, "width", "height"))
			image->Extent((int)arguments["width"], (int)arguments["height"]);
		else if (OnlyContains(arguments, "width", "height", "backgroundColor"))
			image->Extent((int)arguments["width"], (int)arguments["height"], (MagickColor^)arguments["backgroundColor"]);
		else if (OnlyContains(arguments, "width", "height", "gravity"))
			image->Extent((int)arguments["width"], (int)arguments["height"], (Gravity)arguments["gravity"]);
		else if (OnlyContains(arguments, "width", "height", "gravity", "backgroundColor"))
			image->Extent((int)arguments["width"], (int)arguments["height"], (Gravity)arguments["gravity"], (MagickColor^)arguments["backgroundColor"]);
		else
			throw gcnew ArgumentException("Invalid argument combination for 'extent', allowed combinations are: [geometry] [geometry, backgroundColor] [geometry, gravity] [geometry, gravity, backgroundColor] [width, height] [width, height, backgroundColor] [width, height, gravity] [width, height, gravity, backgroundColor]");
	}
	void MagickScript::ExecuteFlip(MagickImage^ image)
	{
		image->Flip();
	}
	void MagickScript::ExecuteFloodFill(XmlElement^ element, MagickImage^ image)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			if (attribute->Name == "alpha")
				arguments["alpha"] = _Variables->GetValue<int>(attribute);
			else if (attribute->Name == "borderColor")
				arguments["borderColor"] = _Variables->GetValue<MagickColor^>(attribute);
			else if (attribute->Name == "color")
				arguments["color"] = _Variables->GetValue<MagickColor^>(attribute);
			else if (attribute->Name == "geometry")
				arguments["geometry"] = _Variables->GetValue<MagickGeometry^>(attribute);
			else if (attribute->Name == "paintMethod")
				arguments["paintMethod"] = _Variables->GetValue<PaintMethod>(attribute);
			else if (attribute->Name == "x")
				arguments["x"] = _Variables->GetValue<int>(attribute);
			else if (attribute->Name == "y")
				arguments["y"] = _Variables->GetValue<int>(attribute);
		}
		for each(XmlElement^ elem in element->SelectNodes("*"))
		{
			arguments[elem->Name] = CreateMagickImage(elem);
		}
		if (OnlyContains(arguments, "alpha", "x", "y", "paintMethod"))
			image->FloodFill((int)arguments["alpha"], (int)arguments["x"], (int)arguments["y"], (PaintMethod)arguments["paintMethod"]);
		else if (OnlyContains(arguments, "color", "geometry"))
			image->FloodFill((MagickColor^)arguments["color"], (MagickGeometry^)arguments["geometry"]);
		else if (OnlyContains(arguments, "color", "geometry", "borderColor"))
			image->FloodFill((MagickColor^)arguments["color"], (MagickGeometry^)arguments["geometry"], (MagickColor^)arguments["borderColor"]);
		else if (OnlyContains(arguments, "color", "x", "y"))
			image->FloodFill((MagickColor^)arguments["color"], (int)arguments["x"], (int)arguments["y"]);
		else if (OnlyContains(arguments, "color", "x", "y", "borderColor"))
			image->FloodFill((MagickColor^)arguments["color"], (int)arguments["x"], (int)arguments["y"], (MagickColor^)arguments["borderColor"]);
		else if (OnlyContains(arguments, "image", "geometry"))
			image->FloodFill((MagickImage^)arguments["image"], (MagickGeometry^)arguments["geometry"]);
		else if (OnlyContains(arguments, "image", "geometry", "borderColor"))
			image->FloodFill((MagickImage^)arguments["image"], (MagickGeometry^)arguments["geometry"], (MagickColor^)arguments["borderColor"]);
		else if (OnlyContains(arguments, "image", "x", "y"))
			image->FloodFill((MagickImage^)arguments["image"], (int)arguments["x"], (int)arguments["y"]);
		else if (OnlyContains(arguments, "image", "x", "y", "borderColor"))
			image->FloodFill((MagickImage^)arguments["image"], (int)arguments["x"], (int)arguments["y"], (MagickColor^)arguments["borderColor"]);
		else
			throw gcnew ArgumentException("Invalid argument combination for 'floodFill', allowed combinations are: [alpha, x, y, paintMethod] [color, geometry] [color, geometry, borderColor] [color, x, y] [color, x, y, borderColor] [image, geometry] [image, geometry, borderColor] [image, x, y] [image, x, y, borderColor]");
	}
	void MagickScript::ExecuteFlop(MagickImage^ image)
	{
		image->Flop();
	}
	void MagickScript::ExecuteFrame(XmlElement^ element, MagickImage^ image)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			if (attribute->Name == "geometry")
				arguments["geometry"] = _Variables->GetValue<MagickGeometry^>(attribute);
			else if (attribute->Name == "height")
				arguments["height"] = _Variables->GetValue<int>(attribute);
			else if (attribute->Name == "innerBevel")
				arguments["innerBevel"] = _Variables->GetValue<int>(attribute);
			else if (attribute->Name == "outerBevel")
				arguments["outerBevel"] = _Variables->GetValue<int>(attribute);
			else if (attribute->Name == "width")
				arguments["width"] = _Variables->GetValue<int>(attribute);
		}
		if (arguments->Count == 0)
			image->Frame();
		else if (OnlyContains(arguments, "geometry"))
			image->Frame((MagickGeometry^)arguments["geometry"]);
		else if (OnlyContains(arguments, "width", "height"))
			image->Frame((int)arguments["width"], (int)arguments["height"]);
		else if (OnlyContains(arguments, "width", "height", "innerBevel", "outerBevel"))
			image->Frame((int)arguments["width"], (int)arguments["height"], (int)arguments["innerBevel"], (int)arguments["outerBevel"]);
		else
			throw gcnew ArgumentException("Invalid argument combination for 'frame', allowed combinations are: [] [geometry] [width, height] [width, height, innerBevel, outerBevel]");
	}
	void MagickScript::ExecuteGamma(XmlElement^ element, MagickImage^ image)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			arguments[attribute->Name] = _Variables->GetValue<double>(attribute);
		}
		if (OnlyContains(arguments, "gammeRed", "gammeGreen", "gammeBlue"))
			image->Gamma((double)arguments["gammeRed"], (double)arguments["gammeGreen"], (double)arguments["gammeBlue"]);
		else if (OnlyContains(arguments, "value"))
			image->Gamma((double)arguments["value"]);
		else
			throw gcnew ArgumentException("Invalid argument combination for 'gamma', allowed combinations are: [gammeRed, gammeGreen, gammeBlue] [value]");
	}
	void MagickScript::ExecuteGaussianBlur(XmlElement^ element, MagickImage^ image)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			if (attribute->Name == "channels")
				arguments["channels"] = _Variables->GetValue<Channels>(attribute);
			else if (attribute->Name == "sigma")
				arguments["sigma"] = _Variables->GetValue<double>(attribute);
			else if (attribute->Name == "width")
				arguments["width"] = _Variables->GetValue<double>(attribute);
		}
		if (OnlyContains(arguments, "width", "sigma"))
			image->GaussianBlur((double)arguments["width"], (double)arguments["sigma"]);
		else if (OnlyContains(arguments, "width", "sigma", "channels"))
			image->GaussianBlur((double)arguments["width"], (double)arguments["sigma"], (Channels)arguments["channels"]);
		else
			throw gcnew ArgumentException("Invalid argument combination for 'gaussianBlur', allowed combinations are: [width, sigma] [width, sigma, channels]");
	}
	void MagickScript::ExecuteHaldClut(XmlElement^ element, MagickImage^ image)
	{
		MagickImage^ image_ = CreateMagickImage(element["image"]);
		image->HaldClut(image_);
	}
	void MagickScript::ExecuteImplode(XmlElement^ element, MagickImage^ image)
	{
		double factor_ = _Variables->GetValue<double>(element, "factor");
		image->Implode(factor_);
	}
	void MagickScript::ExecuteLevel(XmlElement^ element, MagickImage^ image)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			if (attribute->Name == "blackPoint")
				arguments["blackPoint"] = _Variables->GetValue<Magick::Quantum>(attribute);
			else if (attribute->Name == "blackPointPercentage")
				arguments["blackPointPercentage"] = _Variables->GetValue<Percentage>(attribute);
			else if (attribute->Name == "channels")
				arguments["channels"] = _Variables->GetValue<Channels>(attribute);
			else if (attribute->Name == "midpoint")
				arguments["midpoint"] = _Variables->GetValue<double>(attribute);
			else if (attribute->Name == "whitePoint")
				arguments["whitePoint"] = _Variables->GetValue<Magick::Quantum>(attribute);
			else if (attribute->Name == "whitePointPercentage")
				arguments["whitePointPercentage"] = _Variables->GetValue<Percentage>(attribute);
		}
		if (OnlyContains(arguments, "blackPoint", "whitePoint"))
			image->Level((Magick::Quantum)arguments["blackPoint"], (Magick::Quantum)arguments["whitePoint"]);
		else if (OnlyContains(arguments, "blackPoint", "whitePoint", "channels"))
			image->Level((Magick::Quantum)arguments["blackPoint"], (Magick::Quantum)arguments["whitePoint"], (Channels)arguments["channels"]);
		else if (OnlyContains(arguments, "blackPoint", "whitePoint", "midpoint"))
			image->Level((Magick::Quantum)arguments["blackPoint"], (Magick::Quantum)arguments["whitePoint"], (double)arguments["midpoint"]);
		else if (OnlyContains(arguments, "blackPoint", "whitePoint", "midpoint", "channels"))
			image->Level((Magick::Quantum)arguments["blackPoint"], (Magick::Quantum)arguments["whitePoint"], (double)arguments["midpoint"], (Channels)arguments["channels"]);
		else if (OnlyContains(arguments, "blackPointPercentage", "whitePointPercentage"))
			image->Level((Percentage)arguments["blackPointPercentage"], (Percentage)arguments["whitePointPercentage"]);
		else if (OnlyContains(arguments, "blackPointPercentage", "whitePointPercentage", "channels"))
			image->Level((Percentage)arguments["blackPointPercentage"], (Percentage)arguments["whitePointPercentage"], (Channels)arguments["channels"]);
		else if (OnlyContains(arguments, "blackPointPercentage", "whitePointPercentage", "midpoint"))
			image->Level((Percentage)arguments["blackPointPercentage"], (Percentage)arguments["whitePointPercentage"], (double)arguments["midpoint"]);
		else if (OnlyContains(arguments, "blackPointPercentage", "whitePointPercentage", "midpoint", "channels"))
			image->Level((Percentage)arguments["blackPointPercentage"], (Percentage)arguments["whitePointPercentage"], (double)arguments["midpoint"], (Channels)arguments["channels"]);
		else
			throw gcnew ArgumentException("Invalid argument combination for 'level', allowed combinations are: [blackPoint, whitePoint] [blackPoint, whitePoint, channels] [blackPoint, whitePoint, midpoint] [blackPoint, whitePoint, midpoint, channels] [blackPointPercentage, whitePointPercentage] [blackPointPercentage, whitePointPercentage, channels] [blackPointPercentage, whitePointPercentage, midpoint] [blackPointPercentage, whitePointPercentage, midpoint, channels]");
	}
	void MagickScript::ExecuteLower(XmlElement^ element, MagickImage^ image)
	{
		int size_ = _Variables->GetValue<int>(element, "size");
		image->Lower(size_);
	}
	void MagickScript::ExecuteMagnify(MagickImage^ image)
	{
		image->Magnify();
	}
	void MagickScript::ExecuteMedianFilter(XmlElement^ element, MagickImage^ image)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			arguments[attribute->Name] = _Variables->GetValue<double>(attribute);
		}
		if (arguments->Count == 0)
			image->MedianFilter();
		else if (OnlyContains(arguments, "radius"))
			image->MedianFilter((double)arguments["radius"]);
		else
			throw gcnew ArgumentException("Invalid argument combination for 'medianFilter', allowed combinations are: [] [radius]");
	}
	void MagickScript::ExecuteMinify(MagickImage^ image)
	{
		image->Minify();
	}
	void MagickScript::ExecuteModulate(XmlElement^ element, MagickImage^ image)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			arguments[attribute->Name] = _Variables->GetValue<Percentage>(attribute);
		}
		if (OnlyContains(arguments, "brightness"))
			image->Modulate((Percentage)arguments["brightness"]);
		else if (OnlyContains(arguments, "brightness", "saturation"))
			image->Modulate((Percentage)arguments["brightness"], (Percentage)arguments["saturation"]);
		else if (OnlyContains(arguments, "brightness", "saturation", "hue"))
			image->Modulate((Percentage)arguments["brightness"], (Percentage)arguments["saturation"], (Percentage)arguments["hue"]);
		else
			throw gcnew ArgumentException("Invalid argument combination for 'modulate', allowed combinations are: [brightness] [brightness, saturation] [brightness, saturation, hue]");
	}
	void MagickScript::ExecuteMotionBlur(XmlElement^ element, MagickImage^ image)
	{
		double radius_ = _Variables->GetValue<double>(element, "radius");
		double sigma_ = _Variables->GetValue<double>(element, "sigma");
		double angle_ = _Variables->GetValue<double>(element, "angle");
		image->MotionBlur(radius_, sigma_, angle_);
	}
	void MagickScript::ExecuteNegate(XmlElement^ element, MagickImage^ image)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			arguments[attribute->Name] = _Variables->GetValue<bool>(attribute);
		}
		if (arguments->Count == 0)
			image->Negate();
		else if (OnlyContains(arguments, "onlyGrayscale"))
			image->Negate((bool)arguments["onlyGrayscale"]);
		else
			throw gcnew ArgumentException("Invalid argument combination for 'negate', allowed combinations are: [] [onlyGrayscale]");
	}
	void MagickScript::ExecuteNormalize(MagickImage^ image)
	{
		image->Normalize();
	}
	void MagickScript::ExecuteOilPaint(XmlElement^ element, MagickImage^ image)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			arguments[attribute->Name] = _Variables->GetValue<double>(attribute);
		}
		if (arguments->Count == 0)
			image->OilPaint();
		else if (OnlyContains(arguments, "radius"))
			image->OilPaint((double)arguments["radius"]);
		else
			throw gcnew ArgumentException("Invalid argument combination for 'oilPaint', allowed combinations are: [] [radius]");
	}
	void MagickScript::ExecuteOpaque(XmlElement^ element, MagickImage^ image)
	{
		MagickColor^ target_ = _Variables->GetValue<MagickColor^>(element, "target");
		MagickColor^ fill_ = _Variables->GetValue<MagickColor^>(element, "fill");
		image->Opaque(target_, fill_);
	}
	void MagickScript::ExecutePreserveColorType(MagickImage^ image)
	{
		image->PreserveColorType();
	}
	void MagickScript::ExecuteQuantize(XmlElement^ element, MagickImage^ image)
	{
		QuantizeSettings^ settings_ = CreateQuantizeSettings(element["settings"]);
		image->Quantize(settings_);
	}
	void MagickScript::ExecuteRaise(XmlElement^ element, MagickImage^ image)
	{
		int size_ = _Variables->GetValue<int>(element, "size");
		image->Raise(size_);
	}
	void MagickScript::ExecuteRandomThreshold(XmlElement^ element, MagickImage^ image)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			if (attribute->Name == "channels")
				arguments["channels"] = _Variables->GetValue<Channels>(attribute);
			else if (attribute->Name == "high")
				arguments["high"] = _Variables->GetValue<Magick::Quantum>(attribute);
			else if (attribute->Name == "low")
				arguments["low"] = _Variables->GetValue<Magick::Quantum>(attribute);
			else if (attribute->Name == "percentageHigh")
				arguments["percentageHigh"] = _Variables->GetValue<Percentage>(attribute);
			else if (attribute->Name == "percentageLow")
				arguments["percentageLow"] = _Variables->GetValue<Percentage>(attribute);
		}
		if (OnlyContains(arguments, "low", "high"))
			image->RandomThreshold((Magick::Quantum)arguments["low"], (Magick::Quantum)arguments["high"]);
		else if (OnlyContains(arguments, "low", "high", "channels"))
			image->RandomThreshold((Magick::Quantum)arguments["low"], (Magick::Quantum)arguments["high"], (Channels)arguments["channels"]);
		else if (OnlyContains(arguments, "percentageLow", "percentageHigh"))
			image->RandomThreshold((Percentage)arguments["percentageLow"], (Percentage)arguments["percentageHigh"]);
		else if (OnlyContains(arguments, "percentageLow", "percentageHigh", "channels"))
			image->RandomThreshold((Percentage)arguments["percentageLow"], (Percentage)arguments["percentageHigh"], (Channels)arguments["channels"]);
		else
			throw gcnew ArgumentException("Invalid argument combination for 'randomThreshold', allowed combinations are: [low, high] [low, high, channels] [percentageLow, percentageHigh] [percentageLow, percentageHigh, channels]");
	}
	void MagickScript::ExecuteReduceNoise(XmlElement^ element, MagickImage^ image)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			arguments[attribute->Name] = _Variables->GetValue<int>(attribute);
		}
		if (arguments->Count == 0)
			image->ReduceNoise();
		else if (OnlyContains(arguments, "order"))
			image->ReduceNoise((int)arguments["order"]);
		else
			throw gcnew ArgumentException("Invalid argument combination for 'reduceNoise', allowed combinations are: [] [order]");
	}
	void MagickScript::ExecuteRemoveDefine(XmlElement^ element, MagickImage^ image)
	{
		MagickFormat format_ = _Variables->GetValue<MagickFormat>(element, "format");
		String^ name_ = _Variables->GetValue<String^>(element, "name");
		image->RemoveDefine(format_, name_);
	}
	void MagickScript::ExecuteRemoveProfile(XmlElement^ element, MagickImage^ image)
	{
		String^ name_ = _Variables->GetValue<String^>(element, "name");
		image->RemoveProfile(name_);
	}
	void MagickScript::ExecuteRePage(MagickImage^ image)
	{
		image->RePage();
	}
	void MagickScript::ExecuteResize(XmlElement^ element, MagickImage^ image)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			if (attribute->Name == "geometry")
				arguments["geometry"] = _Variables->GetValue<MagickGeometry^>(attribute);
			else if (attribute->Name == "height")
				arguments["height"] = _Variables->GetValue<int>(attribute);
			else if (attribute->Name == "percentage")
				arguments["percentage"] = _Variables->GetValue<Percentage>(attribute);
			else if (attribute->Name == "percentageHeight")
				arguments["percentageHeight"] = _Variables->GetValue<Percentage>(attribute);
			else if (attribute->Name == "percentageWidth")
				arguments["percentageWidth"] = _Variables->GetValue<Percentage>(attribute);
			else if (attribute->Name == "width")
				arguments["width"] = _Variables->GetValue<int>(attribute);
		}
		if (OnlyContains(arguments, "geometry"))
			image->Resize((MagickGeometry^)arguments["geometry"]);
		else if (OnlyContains(arguments, "percentage"))
			image->Resize((Percentage)arguments["percentage"]);
		else if (OnlyContains(arguments, "percentageWidth", "percentageHeight"))
			image->Resize((Percentage)arguments["percentageWidth"], (Percentage)arguments["percentageHeight"]);
		else if (OnlyContains(arguments, "width", "height"))
			image->Resize((int)arguments["width"], (int)arguments["height"]);
		else
			throw gcnew ArgumentException("Invalid argument combination for 'resize', allowed combinations are: [geometry] [percentage] [percentageWidth, percentageHeight] [width, height]");
	}
	void MagickScript::ExecuteRoll(XmlElement^ element, MagickImage^ image)
	{
		int xOffset_ = _Variables->GetValue<int>(element, "xOffset");
		int yOffset_ = _Variables->GetValue<int>(element, "yOffset");
		image->Roll(xOffset_, yOffset_);
	}
	void MagickScript::ExecuteRotate(XmlElement^ element, MagickImage^ image)
	{
		double degrees_ = _Variables->GetValue<double>(element, "degrees");
		image->Rotate(degrees_);
	}
	void MagickScript::ExecuteSample(XmlElement^ element, MagickImage^ image)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			if (attribute->Name == "geometry")
				arguments["geometry"] = _Variables->GetValue<MagickGeometry^>(attribute);
			else if (attribute->Name == "height")
				arguments["height"] = _Variables->GetValue<int>(attribute);
			else if (attribute->Name == "percentage")
				arguments["percentage"] = _Variables->GetValue<Percentage>(attribute);
			else if (attribute->Name == "percentageHeight")
				arguments["percentageHeight"] = _Variables->GetValue<Percentage>(attribute);
			else if (attribute->Name == "percentageWidth")
				arguments["percentageWidth"] = _Variables->GetValue<Percentage>(attribute);
			else if (attribute->Name == "width")
				arguments["width"] = _Variables->GetValue<int>(attribute);
		}
		if (OnlyContains(arguments, "geometry"))
			image->Sample((MagickGeometry^)arguments["geometry"]);
		else if (OnlyContains(arguments, "percentage"))
			image->Sample((Percentage)arguments["percentage"]);
		else if (OnlyContains(arguments, "percentageWidth", "percentageHeight"))
			image->Sample((Percentage)arguments["percentageWidth"], (Percentage)arguments["percentageHeight"]);
		else if (OnlyContains(arguments, "width", "height"))
			image->Sample((int)arguments["width"], (int)arguments["height"]);
		else
			throw gcnew ArgumentException("Invalid argument combination for 'sample', allowed combinations are: [geometry] [percentage] [percentageWidth, percentageHeight] [width, height]");
	}
	void MagickScript::ExecuteScale(XmlElement^ element, MagickImage^ image)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			if (attribute->Name == "geometry")
				arguments["geometry"] = _Variables->GetValue<MagickGeometry^>(attribute);
			else if (attribute->Name == "height")
				arguments["height"] = _Variables->GetValue<int>(attribute);
			else if (attribute->Name == "percentage")
				arguments["percentage"] = _Variables->GetValue<Percentage>(attribute);
			else if (attribute->Name == "percentageHeight")
				arguments["percentageHeight"] = _Variables->GetValue<Percentage>(attribute);
			else if (attribute->Name == "percentageWidth")
				arguments["percentageWidth"] = _Variables->GetValue<Percentage>(attribute);
			else if (attribute->Name == "width")
				arguments["width"] = _Variables->GetValue<int>(attribute);
		}
		if (OnlyContains(arguments, "geometry"))
			image->Scale((MagickGeometry^)arguments["geometry"]);
		else if (OnlyContains(arguments, "percentage"))
			image->Scale((Percentage)arguments["percentage"]);
		else if (OnlyContains(arguments, "percentageWidth", "percentageHeight"))
			image->Scale((Percentage)arguments["percentageWidth"], (Percentage)arguments["percentageHeight"]);
		else if (OnlyContains(arguments, "width", "height"))
			image->Scale((int)arguments["width"], (int)arguments["height"]);
		else
			throw gcnew ArgumentException("Invalid argument combination for 'scale', allowed combinations are: [geometry] [percentage] [percentageWidth, percentageHeight] [width, height]");
	}
	void MagickScript::ExecuteSegment(XmlElement^ element, MagickImage^ image)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			if (attribute->Name == "clusterThreshold")
				arguments["clusterThreshold"] = _Variables->GetValue<double>(attribute);
			else if (attribute->Name == "quantizeColorSpace")
				arguments["quantizeColorSpace"] = _Variables->GetValue<ColorSpace>(attribute);
			else if (attribute->Name == "smoothingThreshold")
				arguments["smoothingThreshold"] = _Variables->GetValue<double>(attribute);
		}
		if (arguments->Count == 0)
			image->Segment();
		else if (OnlyContains(arguments, "quantizeColorSpace", "clusterThreshold", "smoothingThreshold"))
			image->Segment((ColorSpace)arguments["quantizeColorSpace"], (double)arguments["clusterThreshold"], (double)arguments["smoothingThreshold"]);
		else
			throw gcnew ArgumentException("Invalid argument combination for 'segment', allowed combinations are: [] [quantizeColorSpace, clusterThreshold, smoothingThreshold]");
	}
	void MagickScript::ExecuteSetAttribute(XmlElement^ element, MagickImage^ image)
	{
		String^ name_ = _Variables->GetValue<String^>(element, "name");
		String^ value_ = _Variables->GetValue<String^>(element, "value");
		image->SetAttribute(name_, value_);
	}
	void MagickScript::ExecuteSetDefine(XmlElement^ element, MagickImage^ image)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			if (attribute->Name == "flag")
				arguments["flag"] = _Variables->GetValue<bool>(attribute);
			else if (attribute->Name == "format")
				arguments["format"] = _Variables->GetValue<MagickFormat>(attribute);
			else if (attribute->Name == "name")
				arguments["name"] = _Variables->GetValue<String^>(attribute);
			else if (attribute->Name == "value")
				arguments["value"] = _Variables->GetValue<String^>(attribute);
		}
		if (OnlyContains(arguments, "format", "name", "flag"))
			image->SetDefine((MagickFormat)arguments["format"], (String^)arguments["name"], (bool)arguments["flag"]);
		else if (OnlyContains(arguments, "format", "name", "value"))
			image->SetDefine((MagickFormat)arguments["format"], (String^)arguments["name"], (String^)arguments["value"]);
		else
			throw gcnew ArgumentException("Invalid argument combination for 'setDefine', allowed combinations are: [format, name, flag] [format, name, value]");
	}
	void MagickScript::ExecuteShade(XmlElement^ element, MagickImage^ image)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			if (attribute->Name == "azimuth")
				arguments["azimuth"] = _Variables->GetValue<double>(attribute);
			else if (attribute->Name == "colorShading")
				arguments["colorShading"] = _Variables->GetValue<bool>(attribute);
			else if (attribute->Name == "elevation")
				arguments["elevation"] = _Variables->GetValue<double>(attribute);
		}
		if (arguments->Count == 0)
			image->Shade();
		else if (OnlyContains(arguments, "azimuth", "elevation", "colorShading"))
			image->Shade((double)arguments["azimuth"], (double)arguments["elevation"], (bool)arguments["colorShading"]);
		else
			throw gcnew ArgumentException("Invalid argument combination for 'shade', allowed combinations are: [] [azimuth, elevation, colorShading]");
	}
	void MagickScript::ExecuteSharpen(XmlElement^ element, MagickImage^ image)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			if (attribute->Name == "channels")
				arguments["channels"] = _Variables->GetValue<Channels>(attribute);
			else if (attribute->Name == "radius")
				arguments["radius"] = _Variables->GetValue<double>(attribute);
			else if (attribute->Name == "sigma")
				arguments["sigma"] = _Variables->GetValue<double>(attribute);
		}
		if (arguments->Count == 0)
			image->Sharpen();
		else if (OnlyContains(arguments, "channels"))
			image->Sharpen((Channels)arguments["channels"]);
		else if (OnlyContains(arguments, "radius", "sigma"))
			image->Sharpen((double)arguments["radius"], (double)arguments["sigma"]);
		else if (OnlyContains(arguments, "radius", "sigma", "channels"))
			image->Sharpen((double)arguments["radius"], (double)arguments["sigma"], (Channels)arguments["channels"]);
		else
			throw gcnew ArgumentException("Invalid argument combination for 'sharpen', allowed combinations are: [] [channels] [radius, sigma] [radius, sigma, channels]");
	}
	void MagickScript::ExecuteShave(XmlElement^ element, MagickImage^ image)
	{
		int leftRight_ = _Variables->GetValue<int>(element, "leftRight");
		int topBottom_ = _Variables->GetValue<int>(element, "topBottom");
		image->Shave(leftRight_, topBottom_);
	}
	void MagickScript::ExecuteShear(XmlElement^ element, MagickImage^ image)
	{
		double xAngle_ = _Variables->GetValue<double>(element, "xAngle");
		double yAngle_ = _Variables->GetValue<double>(element, "yAngle");
		image->Shear(xAngle_, yAngle_);
	}
	void MagickScript::ExecuteSolarize(XmlElement^ element, MagickImage^ image)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			arguments[attribute->Name] = _Variables->GetValue<double>(attribute);
		}
		if (arguments->Count == 0)
			image->Solarize();
		else if (OnlyContains(arguments, "factor"))
			image->Solarize((double)arguments["factor"]);
		else
			throw gcnew ArgumentException("Invalid argument combination for 'solarize', allowed combinations are: [] [factor]");
	}
	void MagickScript::ExecuteSpread(XmlElement^ element, MagickImage^ image)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			arguments[attribute->Name] = _Variables->GetValue<int>(attribute);
		}
		if (arguments->Count == 0)
			image->Spread();
		else if (OnlyContains(arguments, "amount"))
			image->Spread((int)arguments["amount"]);
		else
			throw gcnew ArgumentException("Invalid argument combination for 'spread', allowed combinations are: [] [amount]");
	}
	void MagickScript::ExecuteStegano(XmlElement^ element, MagickImage^ image)
	{
		MagickImage^ watermark_ = CreateMagickImage(element["watermark"]);
		image->Stegano(watermark_);
	}
	void MagickScript::ExecuteStereo(XmlElement^ element, MagickImage^ image)
	{
		MagickImage^ rightImage_ = CreateMagickImage(element["rightImage"]);
		image->Stereo(rightImage_);
	}
	void MagickScript::ExecuteStrip(MagickImage^ image)
	{
		image->Strip();
	}
	void MagickScript::ExecuteSwirl(XmlElement^ element, MagickImage^ image)
	{
		double degrees_ = _Variables->GetValue<double>(element, "degrees");
		image->Swirl(degrees_);
	}
	void MagickScript::ExecuteTexture(XmlElement^ element, MagickImage^ image)
	{
		MagickImage^ image_ = CreateMagickImage(element["image"]);
		image->Texture(image_);
	}
	void MagickScript::ExecuteThreshold(XmlElement^ element, MagickImage^ image)
	{
		Percentage percentage_ = _Variables->GetValue<Percentage>(element, "percentage");
		image->Threshold(percentage_);
	}
	void MagickScript::ExecuteThumbnail(XmlElement^ element, MagickImage^ image)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			if (attribute->Name == "geometry")
				arguments["geometry"] = _Variables->GetValue<MagickGeometry^>(attribute);
			else if (attribute->Name == "height")
				arguments["height"] = _Variables->GetValue<int>(attribute);
			else if (attribute->Name == "percentage")
				arguments["percentage"] = _Variables->GetValue<Percentage>(attribute);
			else if (attribute->Name == "percentageHeight")
				arguments["percentageHeight"] = _Variables->GetValue<Percentage>(attribute);
			else if (attribute->Name == "percentageWidth")
				arguments["percentageWidth"] = _Variables->GetValue<Percentage>(attribute);
			else if (attribute->Name == "width")
				arguments["width"] = _Variables->GetValue<int>(attribute);
		}
		if (OnlyContains(arguments, "geometry"))
			image->Thumbnail((MagickGeometry^)arguments["geometry"]);
		else if (OnlyContains(arguments, "percentage"))
			image->Thumbnail((Percentage)arguments["percentage"]);
		else if (OnlyContains(arguments, "percentageWidth", "percentageHeight"))
			image->Thumbnail((Percentage)arguments["percentageWidth"], (Percentage)arguments["percentageHeight"]);
		else if (OnlyContains(arguments, "width", "height"))
			image->Thumbnail((int)arguments["width"], (int)arguments["height"]);
		else
			throw gcnew ArgumentException("Invalid argument combination for 'thumbnail', allowed combinations are: [geometry] [percentage] [percentageWidth, percentageHeight] [width, height]");
	}
	void MagickScript::ExecuteTile(XmlElement^ element, MagickImage^ image)
	{
		MagickImage^ image_ = CreateMagickImage(element["image"]);
		CompositeOperator compose_ = _Variables->GetValue<CompositeOperator>(element, "compose");
		image->Tile(image_, compose_);
	}
	void MagickScript::ExecuteTransform(XmlElement^ element, MagickImage^ image)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			arguments[attribute->Name] = _Variables->GetValue<MagickGeometry^>(attribute);
		}
		if (OnlyContains(arguments, "imageGeometry"))
			image->Transform((MagickGeometry^)arguments["imageGeometry"]);
		else if (OnlyContains(arguments, "imageGeometry", "cropGeometry"))
			image->Transform((MagickGeometry^)arguments["imageGeometry"], (MagickGeometry^)arguments["cropGeometry"]);
		else
			throw gcnew ArgumentException("Invalid argument combination for 'transform', allowed combinations are: [imageGeometry] [imageGeometry, cropGeometry]");
	}
	void MagickScript::ExecuteTransformOrigin(XmlElement^ element, MagickImage^ image)
	{
		double x_ = _Variables->GetValue<double>(element, "x");
		double y_ = _Variables->GetValue<double>(element, "y");
		image->TransformOrigin(x_, y_);
	}
	void MagickScript::ExecuteTransformReset(MagickImage^ image)
	{
		image->TransformReset();
	}
	void MagickScript::ExecuteTransformRotation(XmlElement^ element, MagickImage^ image)
	{
		double angle_ = _Variables->GetValue<double>(element, "angle");
		image->TransformRotation(angle_);
	}
	void MagickScript::ExecuteTransformScale(XmlElement^ element, MagickImage^ image)
	{
		double scaleX_ = _Variables->GetValue<double>(element, "scaleX");
		double scaleY_ = _Variables->GetValue<double>(element, "scaleY");
		image->TransformScale(scaleX_, scaleY_);
	}
	void MagickScript::ExecuteTransformSkewX(XmlElement^ element, MagickImage^ image)
	{
		double skewX_ = _Variables->GetValue<double>(element, "skewX");
		image->TransformSkewX(skewX_);
	}
	void MagickScript::ExecuteTransformSkewY(XmlElement^ element, MagickImage^ image)
	{
		double skewY_ = _Variables->GetValue<double>(element, "skewY");
		image->TransformSkewY(skewY_);
	}
	void MagickScript::ExecuteTransparent(XmlElement^ element, MagickImage^ image)
	{
		MagickColor^ color_ = _Variables->GetValue<MagickColor^>(element, "color");
		image->Transparent(color_);
	}
	void MagickScript::ExecuteTrim(MagickImage^ image)
	{
		image->Trim();
	}
	void MagickScript::ExecuteUnsharpmask(XmlElement^ element, MagickImage^ image)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			if (attribute->Name == "amount")
				arguments["amount"] = _Variables->GetValue<double>(attribute);
			else if (attribute->Name == "channels")
				arguments["channels"] = _Variables->GetValue<Channels>(attribute);
			else if (attribute->Name == "radius")
				arguments["radius"] = _Variables->GetValue<double>(attribute);
			else if (attribute->Name == "sigma")
				arguments["sigma"] = _Variables->GetValue<double>(attribute);
			else if (attribute->Name == "threshold")
				arguments["threshold"] = _Variables->GetValue<double>(attribute);
		}
		if (OnlyContains(arguments, "radius", "sigma", "amount", "threshold"))
			image->Unsharpmask((double)arguments["radius"], (double)arguments["sigma"], (double)arguments["amount"], (double)arguments["threshold"]);
		else if (OnlyContains(arguments, "radius", "sigma", "amount", "threshold", "channels"))
			image->Unsharpmask((double)arguments["radius"], (double)arguments["sigma"], (double)arguments["amount"], (double)arguments["threshold"], (Channels)arguments["channels"]);
		else
			throw gcnew ArgumentException("Invalid argument combination for 'unsharpmask', allowed combinations are: [radius, sigma, amount, threshold] [radius, sigma, amount, threshold, channels]");
	}
	void MagickScript::ExecuteWave(XmlElement^ element, MagickImage^ image)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			arguments[attribute->Name] = _Variables->GetValue<double>(attribute);
		}
		if (arguments->Count == 0)
			image->Wave();
		else if (OnlyContains(arguments, "amplitude", "length"))
			image->Wave((double)arguments["amplitude"], (double)arguments["length"]);
		else
			throw gcnew ArgumentException("Invalid argument combination for 'wave', allowed combinations are: [] [amplitude, length]");
	}
	void MagickScript::ExecuteZoom(XmlElement^ element, MagickImage^ image)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			if (attribute->Name == "geometry")
				arguments["geometry"] = _Variables->GetValue<MagickGeometry^>(attribute);
			else if (attribute->Name == "height")
				arguments["height"] = _Variables->GetValue<int>(attribute);
			else if (attribute->Name == "percentage")
				arguments["percentage"] = _Variables->GetValue<Percentage>(attribute);
			else if (attribute->Name == "percentageHeight")
				arguments["percentageHeight"] = _Variables->GetValue<Percentage>(attribute);
			else if (attribute->Name == "percentageWidth")
				arguments["percentageWidth"] = _Variables->GetValue<Percentage>(attribute);
			else if (attribute->Name == "width")
				arguments["width"] = _Variables->GetValue<int>(attribute);
		}
		if (OnlyContains(arguments, "geometry"))
			image->Zoom((MagickGeometry^)arguments["geometry"]);
		else if (OnlyContains(arguments, "percentage"))
			image->Zoom((Percentage)arguments["percentage"]);
		else if (OnlyContains(arguments, "percentageWidth", "percentageHeight"))
			image->Zoom((Percentage)arguments["percentageWidth"], (Percentage)arguments["percentageHeight"]);
		else if (OnlyContains(arguments, "width", "height"))
			image->Zoom((int)arguments["width"], (int)arguments["height"]);
		else
			throw gcnew ArgumentException("Invalid argument combination for 'zoom', allowed combinations are: [geometry] [percentage] [percentageWidth, percentageHeight] [width, height]");
	}
	MagickImage^ MagickScript::ExecuteCollection(XmlElement^ element, MagickImageCollection^ collection)
	{
		switch(element->Name[0])
		{
			case 'c':
			{
				return ExecuteCoalesce(collection);
			}
			case 'd':
			{
				return ExecuteDeconstruct(collection);
			}
			case 'm':
			{
				switch(element->Name[1])
				{
					case 'a':
					{
						return ExecuteMap(element, collection);
					}
					case 'o':
					{
						return ExecuteMosaic(collection);
					}
				}
				break;
			}
			case 'q':
			{
				return ExecuteQuantize(element, collection);
			}
			case 'r':
			{
				switch(element->Name[2])
				{
					case 'P':
					{
						return ExecuteRePage(collection);
					}
					case 'v':
					{
						return ExecuteReverse(collection);
					}
				}
				break;
			}
			case 'a':
			{
				switch(element->Name[6])
				{
					case 'H':
					{
						return ExecuteAppendHorizontally(collection);
					}
					case 'V':
					{
						return ExecuteAppendVertically(collection);
					}
				}
				break;
			}
			case 'f':
			{
				return ExecuteFlatten(collection);
			}
		}
		throw gcnew NotImplementedException(element->Name);
	}
	MagickImage^ MagickScript::ExecuteCoalesce(MagickImageCollection^ collection)
	{
		collection->Coalesce();
		return nullptr;
	}
	MagickImage^ MagickScript::ExecuteDeconstruct(MagickImageCollection^ collection)
	{
		collection->Deconstruct();
		return nullptr;
	}
	MagickImage^ MagickScript::ExecuteMap(XmlElement^ element, MagickImageCollection^ collection)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlElement^ elem in element->SelectNodes("*"))
		{
			arguments[elem->Name] = CreateQuantizeSettings(elem);
		}
		if (arguments->Count == 0)
			{
				collection->Map();
				return nullptr;
			}
		else if (OnlyContains(arguments, "settings"))
			{
				collection->Map((QuantizeSettings^)arguments["settings"]);
				return nullptr;
			}
		else
			throw gcnew ArgumentException("Invalid argument combination for 'map', allowed combinations are: [] [settings]");
	}
	MagickImage^ MagickScript::ExecuteQuantize(XmlElement^ element, MagickImageCollection^ collection)
	{
		QuantizeSettings^ settings_ = CreateQuantizeSettings(element["settings"]);
		collection->Quantize(settings_);
		return nullptr;
	}
	MagickImage^ MagickScript::ExecuteRePage(MagickImageCollection^ collection)
	{
		collection->RePage();
		return nullptr;
	}
	MagickImage^ MagickScript::ExecuteReverse(MagickImageCollection^ collection)
	{
		collection->Reverse();
		return nullptr;
	}
	MagickImage^ MagickScript::ExecuteAppendHorizontally(MagickImageCollection^ collection)
	{
		return collection->AppendHorizontally();
	}
	MagickImage^ MagickScript::ExecuteAppendVertically(MagickImageCollection^ collection)
	{
		return collection->AppendVertically();
	}
	MagickImage^ MagickScript::ExecuteFlatten(MagickImageCollection^ collection)
	{
		return collection->Flatten();
	}
	MagickImage^ MagickScript::ExecuteMosaic(MagickImageCollection^ collection)
	{
		return collection->Mosaic();
	}
	void MagickScript::ExecuteDrawable(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		switch(element->Name[0])
		{
			case 'a':
			{
				switch(element->Name[1])
				{
					case 'f':
					{
						ExecuteAffine(element, drawables);
						return;
					}
					case 'r':
					{
						ExecuteArc(element, drawables);
						return;
					}
				}
				break;
			}
			case 'b':
			{
				ExecuteBezier(element, drawables);
				return;
			}
			case 'c':
			{
				switch(element->Name[1])
				{
					case 'i':
					{
						ExecuteCircle(element, drawables);
						return;
					}
					case 'l':
					{
						ExecuteClipPath(element, drawables);
						return;
					}
					case 'o':
					{
						switch(element->Name[2])
						{
							case 'l':
							{
								ExecuteColor(element, drawables);
								return;
							}
							case 'm':
							{
								ExecuteCompositeImage(element, drawables);
								return;
							}
						}
						break;
					}
				}
				break;
			}
			case 'd':
			{
				switch(element->Name[4])
				{
					case 'A':
					{
						ExecuteDashArray(element, drawables);
						return;
					}
					case 'O':
					{
						ExecuteDashOffset(element, drawables);
						return;
					}
				}
				break;
			}
			case 'e':
			{
				ExecuteEllipse(element, drawables);
				return;
			}
			case 'f':
			{
				switch(element->Name[1])
				{
					case 'i':
					{
						switch(element->Name[4])
						{
							case 'C':
							{
								ExecuteFillColor(element, drawables);
								return;
							}
							case 'O':
							{
								ExecuteFillOpacity(element, drawables);
								return;
							}
							case 'R':
							{
								ExecuteFillRule(element, drawables);
								return;
							}
						}
						break;
					}
					case 'o':
					{
						ExecuteFont(element, drawables);
						return;
					}
				}
				break;
			}
			case 'g':
			{
				ExecuteGravity(element, drawables);
				return;
			}
			case 'l':
			{
				ExecuteLine(element, drawables);
				return;
			}
			case 'm':
			{
				switch(element->Name[1])
				{
					case 'a':
					{
						ExecuteMatte(element, drawables);
						return;
					}
					case 'i':
					{
						ExecuteMiterLimit(element, drawables);
						return;
					}
				}
				break;
			}
			case 'p':
			{
				switch(element->Name[1])
				{
					case 'a':
					{
						ExecutePath(element, drawables);
						return;
					}
					case 'o':
					{
						switch(element->Name[2])
						{
							case 'i':
							{
								if (element->Name->Length == 5)
								{
									ExecutePoint(element, drawables);
									return;
								}
								if (element->Name->Length == 9)
								{
									ExecutePointSize(element, drawables);
									return;
								}
							}
							case 'l':
							{
								switch(element->Name[4])
								{
									case 'g':
									{
										ExecutePolygon(element, drawables);
										return;
									}
									case 'l':
									{
										ExecutePolyline(element, drawables);
										return;
									}
								}
								break;
							}
						}
						break;
					}
					case 'u':
					{
						switch(element->Name[4])
						{
							case 'C':
							{
								ExecutePushClipPath(element, drawables);
								return;
							}
							case 'P':
							{
								ExecutePushPattern(element, drawables);
								return;
							}
						}
						break;
					}
				}
				break;
			}
			case 'r':
			{
				switch(element->Name[1])
				{
					case 'e':
					{
						ExecuteRectangle(element, drawables);
						return;
					}
					case 'o':
					{
						switch(element->Name[2])
						{
							case 't':
							{
								ExecuteRotation(element, drawables);
								return;
							}
							case 'u':
							{
								ExecuteRoundRectangle(element, drawables);
								return;
							}
						}
						break;
					}
				}
				break;
			}
			case 's':
			{
				switch(element->Name[1])
				{
					case 'c':
					{
						ExecuteScaling(element, drawables);
						return;
					}
					case 'k':
					{
						switch(element->Name[4])
						{
							case 'X':
							{
								ExecuteSkewX(element, drawables);
								return;
							}
							case 'Y':
							{
								ExecuteSkewY(element, drawables);
								return;
							}
						}
						break;
					}
					case 't':
					{
						switch(element->Name[6])
						{
							case 'A':
							{
								ExecuteStrokeAntialias(element, drawables);
								return;
							}
							case 'C':
							{
								ExecuteStrokeColor(element, drawables);
								return;
							}
							case 'L':
							{
								switch(element->Name[10])
								{
									case 'C':
									{
										ExecuteStrokeLineCap(element, drawables);
										return;
									}
									case 'J':
									{
										ExecuteStrokeLineJoin(element, drawables);
										return;
									}
								}
								break;
							}
							case 'O':
							{
								ExecuteStrokeOpacity(element, drawables);
								return;
							}
							case 'W':
							{
								ExecuteStrokeWidth(element, drawables);
								return;
							}
						}
						break;
					}
				}
				break;
			}
			case 't':
			{
				switch(element->Name[1])
				{
					case 'e':
					{
						if (element->Name->Length == 4)
						{
							ExecuteText(element, drawables);
							return;
						}
						switch(element->Name[4])
						{
							case 'A':
							{
								ExecuteTextAntialias(element, drawables);
								return;
							}
							case 'D':
							{
								ExecuteTextDecoration(element, drawables);
								return;
							}
							case 'U':
							{
								ExecuteTextUnderColor(element, drawables);
								return;
							}
						}
						break;
					}
					case 'r':
					{
						ExecuteTranslation(element, drawables);
						return;
					}
				}
				break;
			}
			case 'v':
			{
				ExecuteViewbox(element, drawables);
				return;
			}
		}
		throw gcnew NotImplementedException(element->Name);
	}
	void MagickScript::ExecuteAffine(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		double scaleX_ = _Variables->GetValue<double>(element, "scaleX");
		double scaleY_ = _Variables->GetValue<double>(element, "scaleY");
		double shearX_ = _Variables->GetValue<double>(element, "shearX");
		double shearY_ = _Variables->GetValue<double>(element, "shearY");
		double translateX_ = _Variables->GetValue<double>(element, "translateX");
		double translateY_ = _Variables->GetValue<double>(element, "translateY");
		drawables->Add(gcnew DrawableAffine(scaleX_, scaleY_, shearX_, shearY_, translateX_, translateY_));
	}
	void MagickScript::ExecuteArc(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		double startX_ = _Variables->GetValue<double>(element, "startX");
		double startY_ = _Variables->GetValue<double>(element, "startY");
		double endX_ = _Variables->GetValue<double>(element, "endX");
		double endY_ = _Variables->GetValue<double>(element, "endY");
		double startDegrees_ = _Variables->GetValue<double>(element, "startDegrees");
		double endDegrees_ = _Variables->GetValue<double>(element, "endDegrees");
		drawables->Add(gcnew DrawableArc(startX_, startY_, endX_, endY_, startDegrees_, endDegrees_));
	}
	void MagickScript::ExecuteBezier(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		IEnumerable<Coordinate>^ coordinates_ = CreateCoordinates(element);
		drawables->Add(gcnew DrawableBezier(coordinates_));
	}
	void MagickScript::ExecuteCircle(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		double originX_ = _Variables->GetValue<double>(element, "originX");
		double originY_ = _Variables->GetValue<double>(element, "originY");
		double perimeterX_ = _Variables->GetValue<double>(element, "perimeterX");
		double perimeterY_ = _Variables->GetValue<double>(element, "perimeterY");
		drawables->Add(gcnew DrawableCircle(originX_, originY_, perimeterX_, perimeterY_));
	}
	void MagickScript::ExecuteClipPath(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		String^ clipPath_ = _Variables->GetValue<String^>(element, "clipPath");
		drawables->Add(gcnew DrawableClipPath(clipPath_));
	}
	void MagickScript::ExecuteColor(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		double x_ = _Variables->GetValue<double>(element, "x");
		double y_ = _Variables->GetValue<double>(element, "y");
		PaintMethod paintMethod_ = _Variables->GetValue<PaintMethod>(element, "paintMethod");
		drawables->Add(gcnew DrawableColor(x_, y_, paintMethod_));
	}
	void MagickScript::ExecuteCompositeImage(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			if (attribute->Name == "compose")
				arguments["compose"] = _Variables->GetValue<CompositeOperator>(attribute);
			else if (attribute->Name == "offset")
				arguments["offset"] = _Variables->GetValue<MagickGeometry^>(attribute);
			else if (attribute->Name == "x")
				arguments["x"] = _Variables->GetValue<double>(attribute);
			else if (attribute->Name == "y")
				arguments["y"] = _Variables->GetValue<double>(attribute);
		}
		for each(XmlElement^ elem in element->SelectNodes("*"))
		{
			arguments[elem->Name] = CreateMagickImage(elem);
		}
		if (OnlyContains(arguments, "offset", "compose", "image"))
			drawables->Add(gcnew DrawableCompositeImage((MagickGeometry^)arguments["offset"], (CompositeOperator)arguments["compose"], (MagickImage^)arguments["image"]));
		else if (OnlyContains(arguments, "offset", "image"))
			drawables->Add(gcnew DrawableCompositeImage((MagickGeometry^)arguments["offset"], (MagickImage^)arguments["image"]));
		else if (OnlyContains(arguments, "x", "y", "compose", "image"))
			drawables->Add(gcnew DrawableCompositeImage((double)arguments["x"], (double)arguments["y"], (CompositeOperator)arguments["compose"], (MagickImage^)arguments["image"]));
		else if (OnlyContains(arguments, "x", "y", "image"))
			drawables->Add(gcnew DrawableCompositeImage((double)arguments["x"], (double)arguments["y"], (MagickImage^)arguments["image"]));
		else
			throw gcnew ArgumentException("Invalid argument combination for 'compositeImage', allowed combinations are: [offset, compose, image] [offset, image] [x, y, compose, image] [x, y, image]");
	}
	void MagickScript::ExecuteDashArray(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		array<double>^ dash_ = _Variables->GetDoubleArray(element["dash"]);
		drawables->Add(gcnew DrawableDashArray(dash_));
	}
	void MagickScript::ExecuteDashOffset(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		double offset_ = _Variables->GetValue<double>(element, "offset");
		drawables->Add(gcnew DrawableDashOffset(offset_));
	}
	void MagickScript::ExecuteEllipse(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		double originX_ = _Variables->GetValue<double>(element, "originX");
		double originY_ = _Variables->GetValue<double>(element, "originY");
		double radiusX_ = _Variables->GetValue<double>(element, "radiusX");
		double radiusY_ = _Variables->GetValue<double>(element, "radiusY");
		double startDegrees_ = _Variables->GetValue<double>(element, "startDegrees");
		double endDegrees_ = _Variables->GetValue<double>(element, "endDegrees");
		drawables->Add(gcnew DrawableEllipse(originX_, originY_, radiusX_, radiusY_, startDegrees_, endDegrees_));
	}
	void MagickScript::ExecuteFillColor(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		MagickColor^ color_ = _Variables->GetValue<MagickColor^>(element, "color");
		drawables->Add(gcnew DrawableFillColor(color_));
	}
	void MagickScript::ExecuteFillOpacity(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		double opacity_ = _Variables->GetValue<double>(element, "opacity");
		drawables->Add(gcnew DrawableFillOpacity(opacity_));
	}
	void MagickScript::ExecuteFillRule(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		FillRule fillRule_ = _Variables->GetValue<FillRule>(element, "fillRule");
		drawables->Add(gcnew DrawableFillRule(fillRule_));
	}
	void MagickScript::ExecuteFont(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			if (attribute->Name == "family")
				arguments["family"] = _Variables->GetValue<String^>(attribute);
			else if (attribute->Name == "stretch")
				arguments["stretch"] = _Variables->GetValue<FontStretch>(attribute);
			else if (attribute->Name == "style")
				arguments["style"] = _Variables->GetValue<FontStyleType>(attribute);
			else if (attribute->Name == "weight")
				arguments["weight"] = _Variables->GetValue<FontWeight>(attribute);
		}
		if (OnlyContains(arguments, "family"))
			drawables->Add(gcnew DrawableFont((String^)arguments["family"]));
		else if (OnlyContains(arguments, "family", "style", "weight", "stretch"))
			drawables->Add(gcnew DrawableFont((String^)arguments["family"], (FontStyleType)arguments["style"], (FontWeight)arguments["weight"], (FontStretch)arguments["stretch"]));
		else
			throw gcnew ArgumentException("Invalid argument combination for 'font', allowed combinations are: [family] [family, style, weight, stretch]");
	}
	void MagickScript::ExecuteGravity(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		Gravity gravity_ = _Variables->GetValue<Gravity>(element, "gravity");
		drawables->Add(gcnew DrawableGravity(gravity_));
	}
	void MagickScript::ExecuteLine(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		double startX_ = _Variables->GetValue<double>(element, "startX");
		double startY_ = _Variables->GetValue<double>(element, "startY");
		double endX_ = _Variables->GetValue<double>(element, "endX");
		double endY_ = _Variables->GetValue<double>(element, "endY");
		drawables->Add(gcnew DrawableLine(startX_, startY_, endX_, endY_));
	}
	void MagickScript::ExecuteMatte(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		double x_ = _Variables->GetValue<double>(element, "x");
		double y_ = _Variables->GetValue<double>(element, "y");
		PaintMethod paintMethod_ = _Variables->GetValue<PaintMethod>(element, "paintMethod");
		drawables->Add(gcnew DrawableMatte(x_, y_, paintMethod_));
	}
	void MagickScript::ExecuteMiterLimit(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		int miterlimit_ = _Variables->GetValue<int>(element, "miterlimit");
		drawables->Add(gcnew DrawableMiterLimit(miterlimit_));
	}
	void MagickScript::ExecutePath(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		IEnumerable<PathBase^>^ paths_ = CreatePaths(element);
		drawables->Add(gcnew DrawablePath(paths_));
	}
	void MagickScript::ExecutePoint(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		double x_ = _Variables->GetValue<double>(element, "x");
		double y_ = _Variables->GetValue<double>(element, "y");
		drawables->Add(gcnew DrawablePoint(x_, y_));
	}
	void MagickScript::ExecutePointSize(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		double pointSize_ = _Variables->GetValue<double>(element, "pointSize");
		drawables->Add(gcnew DrawablePointSize(pointSize_));
	}
	void MagickScript::ExecutePolygon(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		IEnumerable<Coordinate>^ coordinates_ = CreateCoordinates(element);
		drawables->Add(gcnew DrawablePolygon(coordinates_));
	}
	void MagickScript::ExecutePolyline(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		IEnumerable<Coordinate>^ coordinates_ = CreateCoordinates(element);
		drawables->Add(gcnew DrawablePolyline(coordinates_));
	}
	void MagickScript::ExecutePushClipPath(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		String^ clipPath_ = _Variables->GetValue<String^>(element, "clipPath");
		drawables->Add(gcnew DrawablePushClipPath(clipPath_));
	}
	void MagickScript::ExecutePushPattern(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		String^ id_ = _Variables->GetValue<String^>(element, "id");
		int x_ = _Variables->GetValue<int>(element, "x");
		int y_ = _Variables->GetValue<int>(element, "y");
		int width_ = _Variables->GetValue<int>(element, "width");
		int height_ = _Variables->GetValue<int>(element, "height");
		drawables->Add(gcnew DrawablePushPattern(id_, x_, y_, width_, height_));
	}
	void MagickScript::ExecuteRectangle(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		double upperLeftX_ = _Variables->GetValue<double>(element, "upperLeftX");
		double upperLeftY_ = _Variables->GetValue<double>(element, "upperLeftY");
		double lowerRightX_ = _Variables->GetValue<double>(element, "lowerRightX");
		double lowerRightY_ = _Variables->GetValue<double>(element, "lowerRightY");
		drawables->Add(gcnew DrawableRectangle(upperLeftX_, upperLeftY_, lowerRightX_, lowerRightY_));
	}
	void MagickScript::ExecuteRotation(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		double angle_ = _Variables->GetValue<double>(element, "angle");
		drawables->Add(gcnew DrawableRotation(angle_));
	}
	void MagickScript::ExecuteRoundRectangle(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		double centerX_ = _Variables->GetValue<double>(element, "centerX");
		double centerY_ = _Variables->GetValue<double>(element, "centerY");
		double width_ = _Variables->GetValue<double>(element, "width");
		double height_ = _Variables->GetValue<double>(element, "height");
		double cornerWidth_ = _Variables->GetValue<double>(element, "cornerWidth");
		double cornerHeight_ = _Variables->GetValue<double>(element, "cornerHeight");
		drawables->Add(gcnew DrawableRoundRectangle(centerX_, centerY_, width_, height_, cornerWidth_, cornerHeight_));
	}
	void MagickScript::ExecuteScaling(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		double x_ = _Variables->GetValue<double>(element, "x");
		double y_ = _Variables->GetValue<double>(element, "y");
		drawables->Add(gcnew DrawableScaling(x_, y_));
	}
	void MagickScript::ExecuteSkewX(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		double angle_ = _Variables->GetValue<double>(element, "angle");
		drawables->Add(gcnew DrawableSkewX(angle_));
	}
	void MagickScript::ExecuteSkewY(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		double angle_ = _Variables->GetValue<double>(element, "angle");
		drawables->Add(gcnew DrawableSkewY(angle_));
	}
	void MagickScript::ExecuteStrokeAntialias(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		bool isEnabled_ = _Variables->GetValue<bool>(element, "isEnabled");
		drawables->Add(gcnew DrawableStrokeAntialias(isEnabled_));
	}
	void MagickScript::ExecuteStrokeColor(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		MagickColor^ color_ = _Variables->GetValue<MagickColor^>(element, "color");
		drawables->Add(gcnew DrawableStrokeColor(color_));
	}
	void MagickScript::ExecuteStrokeLineCap(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		LineCap lineCap_ = _Variables->GetValue<LineCap>(element, "lineCap");
		drawables->Add(gcnew DrawableStrokeLineCap(lineCap_));
	}
	void MagickScript::ExecuteStrokeLineJoin(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		LineJoin lineJoin_ = _Variables->GetValue<LineJoin>(element, "lineJoin");
		drawables->Add(gcnew DrawableStrokeLineJoin(lineJoin_));
	}
	void MagickScript::ExecuteStrokeOpacity(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		double opacity_ = _Variables->GetValue<double>(element, "opacity");
		drawables->Add(gcnew DrawableStrokeOpacity(opacity_));
	}
	void MagickScript::ExecuteStrokeWidth(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		double width_ = _Variables->GetValue<double>(element, "width");
		drawables->Add(gcnew DrawableStrokeWidth(width_));
	}
	void MagickScript::ExecuteText(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		System::Collections::Hashtable^ arguments = gcnew System::Collections::Hashtable();
		for each(XmlAttribute^ attribute in element->Attributes)
		{
			if (attribute->Name == "encoding")
				arguments["encoding"] = _Variables->GetValue<Encoding^>(attribute);
			else if (attribute->Name == "value")
				arguments["value"] = _Variables->GetValue<String^>(attribute);
			else if (attribute->Name == "x")
				arguments["x"] = _Variables->GetValue<double>(attribute);
			else if (attribute->Name == "y")
				arguments["y"] = _Variables->GetValue<double>(attribute);
		}
		if (OnlyContains(arguments, "x", "y", "value"))
			drawables->Add(gcnew DrawableText((double)arguments["x"], (double)arguments["y"], (String^)arguments["value"]));
		else if (OnlyContains(arguments, "x", "y", "value", "encoding"))
			drawables->Add(gcnew DrawableText((double)arguments["x"], (double)arguments["y"], (String^)arguments["value"], (Encoding^)arguments["encoding"]));
		else
			throw gcnew ArgumentException("Invalid argument combination for 'text', allowed combinations are: [x, y, value] [x, y, value, encoding]");
	}
	void MagickScript::ExecuteTextAntialias(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		bool isEnabled_ = _Variables->GetValue<bool>(element, "isEnabled");
		drawables->Add(gcnew DrawableTextAntialias(isEnabled_));
	}
	void MagickScript::ExecuteTextDecoration(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		TextDecoration decoration_ = _Variables->GetValue<TextDecoration>(element, "decoration");
		drawables->Add(gcnew DrawableTextDecoration(decoration_));
	}
	void MagickScript::ExecuteTextUnderColor(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		MagickColor^ color_ = _Variables->GetValue<MagickColor^>(element, "color");
		drawables->Add(gcnew DrawableTextUnderColor(color_));
	}
	void MagickScript::ExecuteTranslation(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		double x_ = _Variables->GetValue<double>(element, "x");
		double y_ = _Variables->GetValue<double>(element, "y");
		drawables->Add(gcnew DrawableTranslation(x_, y_));
	}
	void MagickScript::ExecuteViewbox(XmlElement^ element, System::Collections::ObjectModel::Collection<Drawable^>^ drawables)
	{
		int upperLeftX_ = _Variables->GetValue<int>(element, "upperLeftX");
		int upperLeftY_ = _Variables->GetValue<int>(element, "upperLeftY");
		int lowerRightX_ = _Variables->GetValue<int>(element, "lowerRightX");
		int lowerRightY_ = _Variables->GetValue<int>(element, "lowerRightY");
		drawables->Add(gcnew DrawableViewbox(upperLeftX_, upperLeftY_, lowerRightX_, lowerRightY_));
	}
	void MagickScript::ExecutePath(XmlElement^ element, System::Collections::ObjectModel::Collection<PathBase^>^ paths)
	{
		switch(element->Name[0])
		{
			case 'a':
			{
				switch(element->Name[3])
				{
					case 'A':
					{
						ExecuteArcAbs(element, paths);
						return;
					}
					case 'R':
					{
						ExecuteArcRel(element, paths);
						return;
					}
				}
				break;
			}
			case 'c':
			{
				switch(element->Name[7])
				{
					case 'A':
					{
						ExecuteCurvetoAbs(element, paths);
						return;
					}
					case 'R':
					{
						ExecuteCurvetoRel(element, paths);
						return;
					}
				}
				break;
			}
			case 'l':
			{
				switch(element->Name[6])
				{
					case 'A':
					{
						ExecuteLinetoAbs(element, paths);
						return;
					}
					case 'H':
					{
						switch(element->Name[16])
						{
							case 'A':
							{
								ExecuteLinetoHorizontalAbs(element, paths);
								return;
							}
							case 'R':
							{
								ExecuteLinetoHorizontalRel(element, paths);
								return;
							}
						}
						break;
					}
					case 'R':
					{
						ExecuteLinetoRel(element, paths);
						return;
					}
					case 'V':
					{
						switch(element->Name[14])
						{
							case 'A':
							{
								ExecuteLinetoVerticalAbs(element, paths);
								return;
							}
							case 'R':
							{
								ExecuteLinetoVerticalRel(element, paths);
								return;
							}
						}
						break;
					}
				}
				break;
			}
			case 'm':
			{
				switch(element->Name[6])
				{
					case 'A':
					{
						ExecuteMovetoAbs(element, paths);
						return;
					}
					case 'R':
					{
						ExecuteMovetoRel(element, paths);
						return;
					}
				}
				break;
			}
			case 'q':
			{
				switch(element->Name[16])
				{
					case 'A':
					{
						ExecuteQuadraticCurvetoAbs(element, paths);
						return;
					}
					case 'R':
					{
						ExecuteQuadraticCurvetoRel(element, paths);
						return;
					}
				}
				break;
			}
			case 's':
			{
				switch(element->Name[6])
				{
					case 'C':
					{
						switch(element->Name[13])
						{
							case 'A':
							{
								ExecuteSmoothCurvetoAbs(element, paths);
								return;
							}
							case 'R':
							{
								ExecuteSmoothCurvetoRel(element, paths);
								return;
							}
						}
						break;
					}
					case 'Q':
					{
						switch(element->Name[22])
						{
							case 'A':
							{
								ExecuteSmoothQuadraticCurvetoAbs(element, paths);
								return;
							}
							case 'R':
							{
								ExecuteSmoothQuadraticCurvetoRel(element, paths);
								return;
							}
						}
						break;
					}
				}
				break;
			}
		}
		throw gcnew NotImplementedException(element->Name);
	}
	void MagickScript::ExecuteArcAbs(XmlElement^ element, System::Collections::ObjectModel::Collection<PathBase^>^ paths)
	{
		IEnumerable<PathArc^>^ pathArcs_ = CreatePathArcs(element);
		paths->Add(gcnew PathArcAbs(pathArcs_));
	}
	void MagickScript::ExecuteArcRel(XmlElement^ element, System::Collections::ObjectModel::Collection<PathBase^>^ paths)
	{
		IEnumerable<PathArc^>^ pathArcs_ = CreatePathArcs(element);
		paths->Add(gcnew PathArcRel(pathArcs_));
	}
	void MagickScript::ExecuteCurvetoAbs(XmlElement^ element, System::Collections::ObjectModel::Collection<PathBase^>^ paths)
	{
		IEnumerable<PathCurveto^>^ pathCurvetos_ = CreatePathCurvetos(element);
		paths->Add(gcnew PathCurvetoAbs(pathCurvetos_));
	}
	void MagickScript::ExecuteCurvetoRel(XmlElement^ element, System::Collections::ObjectModel::Collection<PathBase^>^ paths)
	{
		IEnumerable<PathCurveto^>^ pathCurvetos_ = CreatePathCurvetos(element);
		paths->Add(gcnew PathCurvetoRel(pathCurvetos_));
	}
	void MagickScript::ExecuteLinetoAbs(XmlElement^ element, System::Collections::ObjectModel::Collection<PathBase^>^ paths)
	{
		IEnumerable<Coordinate>^ coordinates_ = CreateCoordinates(element);
		paths->Add(gcnew PathLinetoAbs(coordinates_));
	}
	void MagickScript::ExecuteLinetoHorizontalAbs(XmlElement^ element, System::Collections::ObjectModel::Collection<PathBase^>^ paths)
	{
		double x_ = _Variables->GetValue<double>(element, "x");
		paths->Add(gcnew PathLinetoHorizontalAbs(x_));
	}
	void MagickScript::ExecuteLinetoHorizontalRel(XmlElement^ element, System::Collections::ObjectModel::Collection<PathBase^>^ paths)
	{
		double x_ = _Variables->GetValue<double>(element, "x");
		paths->Add(gcnew PathLinetoHorizontalRel(x_));
	}
	void MagickScript::ExecuteLinetoRel(XmlElement^ element, System::Collections::ObjectModel::Collection<PathBase^>^ paths)
	{
		IEnumerable<Coordinate>^ coordinates_ = CreateCoordinates(element);
		paths->Add(gcnew PathLinetoRel(coordinates_));
	}
	void MagickScript::ExecuteLinetoVerticalAbs(XmlElement^ element, System::Collections::ObjectModel::Collection<PathBase^>^ paths)
	{
		double x_ = _Variables->GetValue<double>(element, "x");
		paths->Add(gcnew PathLinetoVerticalAbs(x_));
	}
	void MagickScript::ExecuteLinetoVerticalRel(XmlElement^ element, System::Collections::ObjectModel::Collection<PathBase^>^ paths)
	{
		double x_ = _Variables->GetValue<double>(element, "x");
		paths->Add(gcnew PathLinetoVerticalRel(x_));
	}
	void MagickScript::ExecuteMovetoAbs(XmlElement^ element, System::Collections::ObjectModel::Collection<PathBase^>^ paths)
	{
		IEnumerable<Coordinate>^ coordinates_ = CreateCoordinates(element);
		paths->Add(gcnew PathMovetoAbs(coordinates_));
	}
	void MagickScript::ExecuteMovetoRel(XmlElement^ element, System::Collections::ObjectModel::Collection<PathBase^>^ paths)
	{
		IEnumerable<Coordinate>^ coordinates_ = CreateCoordinates(element);
		paths->Add(gcnew PathMovetoRel(coordinates_));
	}
	void MagickScript::ExecuteQuadraticCurvetoAbs(XmlElement^ element, System::Collections::ObjectModel::Collection<PathBase^>^ paths)
	{
		IEnumerable<PathQuadraticCurveto^>^ pathQuadraticCurvetos_ = CreatePathQuadraticCurvetos(element);
		paths->Add(gcnew PathQuadraticCurvetoAbs(pathQuadraticCurvetos_));
	}
	void MagickScript::ExecuteQuadraticCurvetoRel(XmlElement^ element, System::Collections::ObjectModel::Collection<PathBase^>^ paths)
	{
		IEnumerable<PathQuadraticCurveto^>^ pathQuadraticCurvetos_ = CreatePathQuadraticCurvetos(element);
		paths->Add(gcnew PathQuadraticCurvetoRel(pathQuadraticCurvetos_));
	}
	void MagickScript::ExecuteSmoothCurvetoAbs(XmlElement^ element, System::Collections::ObjectModel::Collection<PathBase^>^ paths)
	{
		IEnumerable<Coordinate>^ coordinates_ = CreateCoordinates(element);
		paths->Add(gcnew PathSmoothCurvetoAbs(coordinates_));
	}
	void MagickScript::ExecuteSmoothCurvetoRel(XmlElement^ element, System::Collections::ObjectModel::Collection<PathBase^>^ paths)
	{
		IEnumerable<Coordinate>^ coordinates_ = CreateCoordinates(element);
		paths->Add(gcnew PathSmoothCurvetoRel(coordinates_));
	}
	void MagickScript::ExecuteSmoothQuadraticCurvetoAbs(XmlElement^ element, System::Collections::ObjectModel::Collection<PathBase^>^ paths)
	{
		IEnumerable<Coordinate>^ coordinates_ = CreateCoordinates(element);
		paths->Add(gcnew PathSmoothQuadraticCurvetoAbs(coordinates_));
	}
	void MagickScript::ExecuteSmoothQuadraticCurvetoRel(XmlElement^ element, System::Collections::ObjectModel::Collection<PathBase^>^ paths)
	{
		IEnumerable<Coordinate>^ coordinates_ = CreateCoordinates(element);
		paths->Add(gcnew PathSmoothQuadraticCurvetoRel(coordinates_));
	}
	Coordinate MagickScript::CreateCoordinate(XmlElement^ element)
	{
		double x_ = _Variables->GetValue<double>(element, "x");
		double y_ = _Variables->GetValue<double>(element, "y");
		return Coordinate(x_, y_);
	}
	Collection<Coordinate>^  MagickScript::CreateCoordinates(XmlElement^ element)
	{
		Collection<Coordinate>^ collection = gcnew Collection<Coordinate>();
		for each (XmlElement^ elem in element->SelectNodes("*"))
		{
			collection->Add(CreateCoordinate(elem));
		}
		return collection;
	}
	ColorProfile^ MagickScript::CreateColorProfile(XmlElement^ element)
	{
		if (element->GetAttribute("name") == "AdobeRGB1998")
			return ColorProfile::AdobeRGB1998;
		if (element->GetAttribute("name") == "AppleRGB")
			return ColorProfile::AppleRGB;
		if (element->GetAttribute("name") == "CoatedFOGRA39")
			return ColorProfile::CoatedFOGRA39;
		if (element->GetAttribute("name") == "ColorMatchRGB")
			return ColorProfile::ColorMatchRGB;
		if (element->GetAttribute("name") == "SRGB")
			return ColorProfile::SRGB;
		if (element->GetAttribute("name") == "USWebCoatedSWOP")
			return ColorProfile::USWebCoatedSWOP;
		throw gcnew NotImplementedException(element->Name);
	}
	ImageProfile^ MagickScript::CreateImageProfile(XmlElement^ element)
	{
		String^ name_ = _Variables->GetValue<String^>(element, "name");
		String^ fileName_ = _Variables->GetValue<String^>(element, "fileName");
		return gcnew ImageProfile(name_, fileName_);
	}
	PathArc^ MagickScript::CreatePathArc(XmlElement^ element)
	{
		double x_ = _Variables->GetValue<double>(element, "x");
		double y_ = _Variables->GetValue<double>(element, "y");
		double radiusX_ = _Variables->GetValue<double>(element, "radiusX");
		double radiusY_ = _Variables->GetValue<double>(element, "radiusY");
		double rotationX_ = _Variables->GetValue<double>(element, "rotationX");
		bool useLargeArc_ = _Variables->GetValue<bool>(element, "useLargeArc");
		bool useSweep_ = _Variables->GetValue<bool>(element, "useSweep");
		return gcnew PathArc(x_, y_, radiusX_, radiusY_, rotationX_, useLargeArc_, useSweep_);
	}
	Collection<PathArc^>^  MagickScript::CreatePathArcs(XmlElement^ element)
	{
		Collection<PathArc^>^ collection = gcnew Collection<PathArc^>();
		for each (XmlElement^ elem in element->SelectNodes("*"))
		{
			collection->Add(CreatePathArc(elem));
		}
		return collection;
	}
	PathCurveto^ MagickScript::CreatePathCurveto(XmlElement^ element)
	{
		double x_ = _Variables->GetValue<double>(element, "x");
		double y_ = _Variables->GetValue<double>(element, "y");
		double x1_ = _Variables->GetValue<double>(element, "x1");
		double y1_ = _Variables->GetValue<double>(element, "y1");
		double x2_ = _Variables->GetValue<double>(element, "x2");
		double y2_ = _Variables->GetValue<double>(element, "y2");
		return gcnew PathCurveto(x_, y_, x1_, y1_, x2_, y2_);
	}
	Collection<PathCurveto^>^  MagickScript::CreatePathCurvetos(XmlElement^ element)
	{
		Collection<PathCurveto^>^ collection = gcnew Collection<PathCurveto^>();
		for each (XmlElement^ elem in element->SelectNodes("*"))
		{
			collection->Add(CreatePathCurveto(elem));
		}
		return collection;
	}
	PathQuadraticCurveto^ MagickScript::CreatePathQuadraticCurveto(XmlElement^ element)
	{
		double x_ = _Variables->GetValue<double>(element, "x");
		double y_ = _Variables->GetValue<double>(element, "y");
		double x1_ = _Variables->GetValue<double>(element, "x1");
		double y1_ = _Variables->GetValue<double>(element, "y1");
		return gcnew PathQuadraticCurveto(x_, y_, x1_, y1_);
	}
	Collection<PathQuadraticCurveto^>^  MagickScript::CreatePathQuadraticCurvetos(XmlElement^ element)
	{
		Collection<PathQuadraticCurveto^>^ collection = gcnew Collection<PathQuadraticCurveto^>();
		for each (XmlElement^ elem in element->SelectNodes("*"))
		{
			collection->Add(CreatePathQuadraticCurveto(elem));
		}
		return collection;
	}
	MagickReadSettings^ MagickScript::CreateMagickReadSettings(XmlElement^ element)
	{
		if (element == nullptr)
			return nullptr;
		MagickReadSettings^ result = gcnew MagickReadSettings();
		result->ColorSpace = _Variables->GetValue<Nullable<ColorSpace>>(element, "colorSpace");
		result->Density = _Variables->GetValue<MagickGeometry^>(element, "density");
		result->Format = _Variables->GetValue<Nullable<MagickFormat>>(element, "format");
		result->Height = _Variables->GetValue<Nullable<Int32>>(element, "height");
		result->PixelStorage = CreatePixelStorageSettings(element["pixelStorage"]);
		result->UseMonochrome = _Variables->GetValue<Nullable<bool>>(element, "useMonochrome");
		result->Width = _Variables->GetValue<Nullable<Int32>>(element, "width");
		XmlElement^ setDefine = (XmlElement^)element->SelectSingleNode("setDefine");
		if (setDefine != nullptr)
		{
			MagickFormat format_ = XmlHelper::GetAttribute<MagickFormat>(setDefine, "format");
			String^ name_ = XmlHelper::GetAttribute<String^>(setDefine, "name");
			String^ value_ = XmlHelper::GetAttribute<String^>(setDefine, "value");
			result->SetDefine(format_,name_,value_);
		}
		return result;
	}
	PixelStorageSettings^ MagickScript::CreatePixelStorageSettings(XmlElement^ element)
	{
		if (element == nullptr)
			return nullptr;
		PixelStorageSettings^ result = gcnew PixelStorageSettings();
		result->Mapping = _Variables->GetValue<String^>(element, "mapping");
		result->StorageType = _Variables->GetValue<StorageType>(element, "storageType");
		return result;
	}
	QuantizeSettings^ MagickScript::CreateQuantizeSettings(XmlElement^ element)
	{
		if (element == nullptr)
			return nullptr;
		QuantizeSettings^ result = gcnew QuantizeSettings();
		result->Colors = _Variables->GetValue<int>(element, "colors");
		result->ColorSpace = _Variables->GetValue<ColorSpace>(element, "colorSpace");
		result->Dither = _Variables->GetValue<bool>(element, "dither");
		result->MeasureErrors = _Variables->GetValue<bool>(element, "measureErrors");
		result->TreeDepth = _Variables->GetValue<int>(element, "treeDepth");
		return result;
	}
}
#pragma warning (default: 4100)
