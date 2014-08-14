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
* Description:  ECOM plugin interface for find in music shop
*
*/



#ifndef MPX_FIND_IN_MUSICSHOP_H
#define MPX_FIND_IN_MUSICSHOP_H

// CONSTANTS
const TUid KSchemeHandlerDefinitionUid = { 0x101FFB53 };

/**
* Find in Music Shop ECOM plugin class
*/
class CMPXFindInMShop : public CBase
    {
    public:  // Constructors and destructor

        /**
        * Two-phased constructor.
        */
        inline static CMPXFindInMShop* NewL();

        /**
        * Destructor.
        */
        inline virtual ~CMPXFindInMShop();

    public: // New functions

        /**
        * Create Search String
        *
        * @since S60 3.2.3
        * @param song name, artist name, album name, composer name and genre
        * @return HBufC* for the constructed string, and ownership of return object is transferred
        */
        virtual HBufC* CreateSearchURLL( const TDesC& aSongName,
                                          const TDesC& aArtistName,
                                          const TDesC& aAlbumName,
                                          const TDesC& aComposer,
                                          const TDesC& aGenre ) = 0;
    private:    // Data

        TUid iDtorKey; // Destructor key for ECOM

    };

#include <mpxfindinmusicshop.inl>

#endif      // MPX_FIND_IN_MUSICSHOP_H

// End of File
