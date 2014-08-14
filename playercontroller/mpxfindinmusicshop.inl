/*
* Copyright (c) 2006-2007 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:  ECOM inline loading file
*
*/



// INCLUDE FILES
#include <e32base.h>
#include <ecom/ecom.h>  
#include "mpxfindinmusicshop.h"

// ============================ MEMBER FUNCTIONS ===============================

// -----------------------------------------------------------------------------
// CMPXFindInMShop::~CMPXFindInMShop
// Standard virtual destructor
// -----------------------------------------------------------------------------
//
CMPXFindInMShop::~CMPXFindInMShop()
      {
      REComSession::DestroyedImplementation( iDtorKey );
      }
          
// -----------------------------------------------------------------------------
// CMPXFindInMShop::CMPXFindInMShop
// C++ default constructor can NOT contain any code, that
// might leave.
// -----------------------------------------------------------------------------
//
CMPXFindInMShop* CMPXFindInMShop::NewL()
    {
    // Create the ecom implementation
    // plugin dll must reside in ROM in order to be loaded!
    //
    CMPXFindInMShop* imp = NULL;
    RImplInfoPtrArray plugins;
    REComSession::ListImplementationsL( KSchemeHandlerDefinitionUid, plugins );
    
    TInt latestVersion(KErrNotFound);
    TInt current_version(0);
    // Find largest version number from the plugins
    for( TInt i=0; i<plugins.Count(); ++i )
        {
        CImplementationInformation* info = plugins[i];
        current_version = info->Version();
        if ( current_version > latestVersion )
            {
            latestVersion = current_version;
            TUid uid = info->ImplementationUid();
            imp = reinterpret_cast<CMPXFindInMShop*>
                ( REComSession::CreateImplementationL( uid, _FOFF( CMPXFindInMShop, iDtorKey ) ) );        
            }
        }

    plugins.ResetAndDestroy();
    plugins.Close();
    return imp;
    }
    
//  End of File  
