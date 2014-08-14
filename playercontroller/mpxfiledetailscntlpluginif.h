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


#ifndef __FILEDETAILSCNTLPLUGINIF_H__
#define __FILEDETAILSCNTLPLUGINIF_H__

#include <e32base.h>


class CMPXFileDetailsPlugin : public CBase
{
public:
	static CMPXFileDetailsPlugin* NewL(const TUid& aImplementationUid);

	virtual ~CMPXFileDetailsPlugin();
	
	virtual TPtrC GetAdditionalLabelLC(TUint32 aFourCCCode) = 0;

protected:
    CMPXFileDetailsPlugin();


private:
	TUid iDtorKey;
};
	
#include <ecom/ecom.h>
#include "mpxfiledetailscntlpluginif.inl"

#endif
