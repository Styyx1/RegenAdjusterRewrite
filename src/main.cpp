#include "Settings.h"
#include "gmst.h"
#include "Hooks.h"
#include "Papyrus.h"

void InitListener(SKSE::MessagingInterface::Message* a_msg) 
{
	switch (a_msg->type)
	{
	case SKSE::MessagingInterface::kDataLoaded:		
		Hooks::InstallHooks();
		if (Settings::Values::bChangeGameSettings.GetValue()) {
			GMST::SetSettings();
		}		
		break;

	case SKSE::MessagingInterface::kPostLoadGame:
		if (Settings::Values::bChangeGameSettings.GetValue()) {
			GMST::SetSettings();
		}
		break;

	default:
		break;
	}
}

SKSEPluginLoad(const SKSE::LoadInterface* a_skse)
{
	SKSE::Init(a_skse);
	Settings::Update();
	SKSE::GetMessagingInterface()->RegisterListener(InitListener);
	SKSE::GetPapyrusInterface()->Register(RegenAdjuster::Papyrus::Register);

	return true;
}
