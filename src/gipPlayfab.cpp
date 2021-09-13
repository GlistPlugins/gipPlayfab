/*
 * gipPlayfab.cpp
 *
 *  Created on: 13 Sep 2021
 *      Author: noyan
 */

#include "gipPlayfab.h"

bool gipPlayfab::finished = false;
const std::string gipPlayfab::titleID = "3F336";

gipPlayfab::gipPlayfab() {
	PlayFabSettings::staticSettings->titleId = titleID;
}

gipPlayfab::~gipPlayfab() {
}

void gipPlayfab::registerPlayFabAccount(const std::string& username, const std::string& email, const std::string& password, const std::string& displayName) {
	RegisterPlayFabUserRequest request;
	request.DisplayName = displayName;
	request.Email = email;
	request.Password = password;
	request.Username = username;

	PlayFabClientAPI::RegisterPlayFabUser(request, OnRegisterSuccess, OnRegisterFail);
}

void gipPlayfab::login(const std::string& username, const std::string& password) {

	LoginWithPlayFabRequest request;
	request.Username = username;
	request.Password = password;

	PlayFabClientAPI::LoginWithPlayFab(request, OnLoginSuccess, OnLoginFail);

	while (PlayFabClientAPI::Update() != 0)
		sleep(1);
}

void gipPlayfab::OnLoginSuccess(const LoginResult& result, void* customData) {
	gLogi("gipPlayfab") << "Login successful.";
	finished = true;
}

void gipPlayfab::OnLoginFail(const PlayFabError& error, void* customData) {
	gLogi("gipPlayfab") << "Something went wrong with your first API call.\n";
	gLogi("gipPlayfab") << "Here's some debug information:\n";
	gLogi("gipPlayfab") << error.GenerateErrorReport();
	finished = true;
}

void gipPlayfab::OnRegisterSuccess(const RegisterPlayFabUserResult& result, void* customData) {
	gLogi("gipPlayfab") << "Register Success usr: " << result.Username << " id: " << result.PlayFabId;
}

void gipPlayfab::OnRegisterFail(const PlayFabError& error, void* customData) {
	gLogi("gipPlayfab") << "Something went wrong with register.\n";
	gLogi("gipPlayfab") << "Here's some debug information:\n";
	gLogi("gipPlayfab") << error.GenerateErrorReport();
}
