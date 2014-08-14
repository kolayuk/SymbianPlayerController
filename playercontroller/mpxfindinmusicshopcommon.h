/*
* Copyright (c) 2007 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Contains the const between mpxmusicplayer and musicshop
*
*/


#ifndef CMPXFINDINMUSICSHOPCOMMON_H
#define CMPXFINDINMUSICSHOPCOMMON_H


// CONST DECLARATION

// P/S Keys for find in music shop
const TUint KMShopCategoryId = 0;
const TUint KMShopCategoryName = 1;

// Indicate that P/S key KMShopCategoryId 
// is not valid for Find In Music Shop.
const TUint KFindInMShopKeyInValid = 0x0;
// P/S key KMShopCategoryId 
// is valid for Find In Music Shop.
const TUint KFindInMShopKeyValid = 0xF;

// The following constants need to match with the RProperty::Define for
// RProperty::EText which has maximum size of 512 bytes in the Collection
// View.

// The final search string URL with Title, Artist, and Album has this
// max size. Increase this size when RProperty::ELargeText is used
const TInt KSearchUrlMaxSize = 512;

// Max size from P/S stored search string created from Collection View.
const TInt KCategoryValueMaxSize = 512;

#endif // CMPXFINDINMUSICSHOPCOMMON_H

// End of File