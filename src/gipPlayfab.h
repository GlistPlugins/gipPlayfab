/*
 * gipPlayfab.h
 *
 *  Created on: 13 Sep 2021
 *      Author: noyan
 *      		Sinem Algul
 *      		Furkan Celenk
 *
 *
 */

#ifndef SRC_GIPPLAYFAB_H_
#define SRC_GIPPLAYFAB_H_

#include "gBasePlugin.h"
#include "playfab/PlayFabClientDataModels.h"
#include "playfab/PlayFabClientApi.h"
#include "playfab/PlayFabSettings.h"
#include "playfab/PlayFabApiSettings.h"
#include "playfab/PlayFabMultiplayerDataModels.h"
#include "playfab/PlayFabMultiplayerApi.h"
#include "playfab/PlayFabDataDataModels.h"
#include "playfab/PlayFabAuthenticationApi.h"
#include "playfab/PlayFabAuthenticationContext.h"
#include "playfab/PlayFabProfilesApi.h"
#include "playfab/PlayFabProfilesDataModels.h"
#include <unistd.h>

using namespace PlayFab;
using namespace ClientModels;
using namespace ProfilesModels;
using namespace MultiplayerModels;
using namespace DataModels;
using namespace AuthenticationModels;


class gipPlayfab : public gBasePlugin{
public:
	gipPlayfab();
	virtual ~gipPlayfab();

	//
	void registerPlayFabAccount(const std::string& username, const std::string& email, const std::string& password, const std::string& displayName);
	void login(const std::string& username, const std::string& password);
	void createMatchmakingTicket(const int& giveupafterseconds);
	PlayFab::MultiplayerModels::GetMatchmakingTicketResult checkMatchmakingTicket(const std::string& ticketid);
	void joinMatch();
	void canceledMatch();

	void openLobby();

	bool isTicketIdReceived();
	bool isTicketCanceled();
	static PlayFab::MultiplayerModels::CreateMatchmakingTicketResult createticketresult;

private:
	static void OnLoginSuccess(const LoginResult& result, void* customData);
	static void OnLoginFail(const PlayFabError& error, void* customData);
	static void OnRegisterSuccess(const RegisterPlayFabUserResult& result, void* customData);
	static void OnRegisterFail(const PlayFabError& error, void* customData);
	static void OnMatchmakingTicketCreated(const CreateMatchmakingTicketResult& result, void* customData);
	static void OnMatchmakingTicketFail(const PlayFabError& error, void* customData);
	static void OnCheckMatchmakingTicket(const GetMatchmakingTicketResult& result, void* customData);
	static void OnCheckMatchmakingFail(const PlayFabError& error, void* customData);
	static void OnGetMatchResult(const GetMatchResult& result, void* customData);
	static void OnGetMatchFail(const PlayFabError& error, void* customData);
	static void OnTicketCanceled(const CancelMatchmakingTicketResult& result, void* customData);
	static void OnTicketCanceledFail(const PlayFabError& error, void* customData);

	static bool finished;
	static bool ticketidreceived;
	static bool ticketcanceled;
	static const std::string titleID;
	static std::string myid;
	static std::string mytitleid;
	static std::string myentitytype;
	static std::string matchid;
	static std::string myqueuename;
};

#endif /* SRC_GIPPLAYFAB_H_ */
