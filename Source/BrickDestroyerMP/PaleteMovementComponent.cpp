// Fill out your copyright notice in the Description page of Project Settings.


#include "PaleteMovementComponent.h"

void UPaleteMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    if (!PawnOwner || !UpdatedComponent || ShouldSkipUpdate(DeltaTime))
    {
        return;
    }
    FVector DesiredMovementThisFrame = ConsumeInputVector().GetClampedToMaxSize(1.0f) * DeltaTime * 1000.f * (*speed);

    if (!DesiredMovementThisFrame.IsNearlyZero())
    {
        FHitResult Hit;
        SafeMoveUpdatedComponent(DesiredMovementThisFrame, UpdatedComponent->GetComponentRotation(), true, Hit);
    }
}

void UPaleteMovementComponent::Init(float* aspeed)
{
    speed = aspeed;
}