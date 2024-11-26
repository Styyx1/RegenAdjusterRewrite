#pragma once

namespace GMST {

	static bool SetGMST(const char* a_setting, float a_set) {

		if (auto set = RE::GameSettingCollection::GetSingleton()) {
			if (auto setting = set->GetSetting(a_setting)) {
				setting->data.f = a_set;
				return true;
			} else {
				logs::info("Invalid GMST ptr");
				return false;
			}
		} else {
			logs::info("Invalid SettingCollection ptr");
			return false;
		}

	};

};