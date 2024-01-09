/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Howaajin. All rights reserved.
 *  Licensed under the MIT License. See License in the project root for license information.
 *--------------------------------------------------------------------------------------------*/

#pragma once

#include "CoreMinimal.h"
#include "FormatterSettings.generated.h"

UENUM()
enum class EGraphFormatterPositioningAlgorithm
{
    EEvenlyInLayer UMETA(DisplayName = "Place node evenly in layer"),
    EFastAndSimpleMethodTop UMETA(DisplayName = "FAS Top"),
    EFastAndSimpleMethodMedian UMETA(DisplayName = "FAS Median"),
    ELayerSweep UMETA(DisplayName = "Layer sweep"),
};

UCLASS(config = Editor)
class GRAPHFORMATTER_API UFormatterSettings : public UObject
{
public:
    GENERATED_BODY()

    UFormatterSettings();

    /** Enable auto detect Graph Editor */
    UPROPERTY(config, EditAnywhere, Category = "Options")
    bool AutoDetectGraphEditor;

    /** All Asset types supported */
    UPROPERTY(config, EditAnywhere, Category = "Options")
    TMap<FString, bool> SupportedAssetTypes;

    /** Toolbar toggle */
    UPROPERTY(config, EditAnywhere, Category = "Options")
    bool DisableToolbar;

    /** Positioning algorithm*/
    UPROPERTY(config, EditAnywhere, Category = "Options")
    EGraphFormatterPositioningAlgorithm PositioningAlgorithm;

    /** Border thickness */
    UPROPERTY(config, EditAnywhere, Category = "Options", meta = (ClampMin = 1))
    int32 CommentBorder;

    /** Spacing between two layers */
    UPROPERTY(config, EditAnywhere, Category = "Options", meta = (ClampMin = 0))
    int32 HorizontalSpacing;

    /** Spacing between two nodes */
    UPROPERTY(config, EditAnywhere, Category = "Options", meta = (ClampMin = 0))
    int32 VerticalSpacing;


    /** Whether to enable parameter grouping in Blueprint Editor */
    UPROPERTY(config, EditAnywhere, Category = "Options")
    bool bEnableBlueprintParameterGroup;

    /* Spacing factor that multiply with HorizontalSpacing and VerticalSpacing in parameter group */
    UPROPERTY(config, EditAnywhere, Category = "Options", meta = (EditCondition = "bEnableBlueprintParameterGroup"))
    FVector2D SpacingFactorOfParameterGroup;

    /** Vertex ordering max iterations */
    UPROPERTY(config, EditAnywhere, Category = "Performance", meta = (ClampMin = 0, ClampMax = 100))
    int32 MaxOrderingIterations;

    /** Straight connections old settings */
    UPROPERTY(config, Category= "Graph Formatter", BlueprintReadWrite)
    FVector2D ForwardSplineTangentFromHorizontalDelta;
    UPROPERTY(config, Category= "Graph Formatter", BlueprintReadWrite)
    FVector2D ForwardSplineTangentFromVerticalDelta;
    UPROPERTY(config, Category= "Graph Formatter", BlueprintReadWrite)
    FVector2D BackwardSplineTangentFromHorizontalDelta;
    UPROPERTY(config, Category= "Graph Formatter", BlueprintReadWrite)
    FVector2D BackwardSplineTangentFromVerticalDelta;
};
