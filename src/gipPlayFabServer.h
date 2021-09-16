/*
 * gipPlayFabServer.h
 *
 *  Created on: 16 Eyl 2021
 *      Author: kayra
 */

#ifndef SRC_GIPPLAYFABSERVER_H_
#define SRC_GIPPLAYFABSERVER_H_

#define ENABLE_PLAYFABSERVER_API
#include "playfab/PlayFabServerDataModels.h"
#include "playfab/PlayFabServerApi.h"
#include "gBasePlugin.h"

using namespace PlayFab;
using namespace ServerModels;

class gipPlayFabServer : public gBasePlugin {
public:
	gipPlayFabServer();
	virtual ~gipPlayFabServer();

	void registerGame();

private:
	static void OnRegisterGameSuccess(const RegisterGameResponse& response, void* customData);
	static void OnRegisterGameFail(const PlayFabError& error, void* customData);
};

#endif /* SRC_GIPPLAYFABSERVER_H_ */
