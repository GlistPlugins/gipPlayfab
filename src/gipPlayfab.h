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

	void registerPlayFabAccount(const std::string& username, const std::string& email, const std::string& password, const std::string& displayName);
	void login(const std::string& username, const std::string& password);

	void openLobby();

private:
	static void OnLoginSuccess(const LoginResult& result, void* customData);
	static void OnLoginFail(const PlayFabError& error, void* customData);
	static void OnRegisterSuccess(const RegisterPlayFabUserResult& result, void* customData);
	static void OnRegisterFail(const PlayFabError& error, void* customData);

	static bool finished;

	static const std::string titleID;
};

#endif /* SRC_GIPPLAYFAB_H_ */
