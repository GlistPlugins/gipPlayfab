/*
 * gipPlayfab.h
 *
 *  Created on: 13 Sep 2021
 *      Author: noyan
 */

#ifndef SRC_GIPPLAYFAB_H_
#define SRC_GIPPLAYFAB_H_

#include "gBasePlugin.h"
#include "playfab/PlayFabClientDataModels.h"
#include "playfab/PlayFabServerDataModels.h"
#include "playfab/PlayFabClientApi.h"
#include "playfab/PlayFabSettings.h"
#include "playfab/PlayFabApiSettings.h"
#include <unistd.h>

using namespace PlayFab;
using namespace ClientModels;

class gipPlayfab : public gBasePlugin{
public:
	gipPlayfab();
	virtual ~gipPlayfab();

	void setTitleID(const std::string& titleID);
	void registerPlayFabAccount(const std::string& username, const std::string& email, const std::string& password, const std::string& displayName);
	void login(const std::string& username, const std::string& password);

	void update();

	void openLobby();

private:
	static void OnStartGameSuccess(const StartGameResult& result, void* customData);
	static void OnLoginSuccess(const LoginResult& result, void* customData);
	static void OnRegisterSuccess(const RegisterPlayFabUserResult& result, void* customData);

	static void OnRequestFail(const PlayFabError& error, void* customData);

	struct RequestData {
		std::string requestname;
	};

	static bool finished;

	std::string titleID;
};

#endif /* SRC_GIPPLAYFAB_H_ */
