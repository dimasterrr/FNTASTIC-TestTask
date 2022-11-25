#include "TurtlesGameModeBase.h"
#include "Turtles/Characters/PlayerCharacter.h"

ATurtlesGameModeBase::ATurtlesGameModeBase()
{
	DefaultPawnClass = APlayerCharacter::StaticClass();
}
