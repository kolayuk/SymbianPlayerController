/*
* Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:   Interface for filedetails cntl plugin.*
*/

// Version : %version: 1 %

inline CMPXFileDetailsPlugin* CMPXFileDetailsPlugin::NewL(const TUid& aImplementationUid)
{
	TAny* any = REComSession::CreateImplementationL(aImplementationUid, _FOFF(CMPXFileDetailsPlugin, iDtorKey));
	CMPXFileDetailsPlugin* object = REINTERPRET_CAST(CMPXFileDetailsPlugin*, any);
	return object;
}

inline CMPXFileDetailsPlugin::~CMPXFileDetailsPlugin()
{
	REComSession::DestroyedImplementation(iDtorKey);
}

inline CMPXFileDetailsPlugin::CMPXFileDetailsPlugin()
{
}

