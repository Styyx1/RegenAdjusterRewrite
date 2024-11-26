#include "Settings.h"
#include "Hooks.h"

void InitListener(SKSE::MessagingInterface::Message* a_msg) 
{
	switch (a_msg->type)
	{
	case SKSE::MessagingInterface::kDataLoaded:
		Settings::Update();
		Hooks::InstallHooks();
		break;

	default:
		break;
	}
}

SKSEPluginLoad(const SKSE::LoadInterface* a_skse)
{
	SKSE::Init(a_skse);

	SKSE::GetMessagingInterface()->RegisterListener(InitListener);

	return true;
}
