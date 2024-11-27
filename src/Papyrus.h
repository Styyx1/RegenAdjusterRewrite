#pragma once

#include "Settings.h"

namespace RegenAdjuster
{
	class Papyrus
	{
	public:
		static bool Register(RE::BSScript::IVirtualMachine* a_vm)
		{
			a_vm->RegisterFunction("GetVersion"sv, CLASS_NAME, GetVersion, true);
			a_vm->RegisterFunction("UpdateSettings"sv, CLASS_NAME, UpdateSettings);
			SKSE::log::info("Registered funcs for class {:s}"sv, CLASS_NAME);

			return true;
		}

	private:
		inline static constexpr auto CLASS_NAME{ "RegenAdjuster"sv };

		enum
		{
			kVersion = 1
		};

		static std::int32_t GetVersion(RE::StaticFunctionTag*)
		{
			return kVersion;
		}

		static void UpdateSettings(RE::StaticFunctionTag*)
		{
			Settings::Update();
		}
	};
}