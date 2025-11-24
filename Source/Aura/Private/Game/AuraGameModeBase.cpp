// Copyright Blacksheep1337


#include "Game/AuraGameModeBase.h"

#include "Player/AuraPlayerState.h"

AAuraGameModeBase::AAuraGameModeBase()
{
	PlayerStateClass = AAuraPlayerState::StaticClass();
}
