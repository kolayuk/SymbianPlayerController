/*
* Copyright (c) 2006 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Class declaration of MMPXUtilObserver.
*
*/


#ifndef MMPXALBUMARTUTILOBSERVER_H
#define MMPXALBUMARTUTILOBSERVER_H

#include <e32def.h>

class CFbsBitmap;

// CLASS DECLARATION

/**
*  Observer class for Async util operation
*/
NONSHARABLE_CLASS(MMPXAlbumArtUtilObserver)
    {
public:
    /**
    * Notify that extraction of album art started.
    */
    virtual void ExtractAlbumArtStarted() = 0;

    /**
    * Notify that extraction of album art completed.
    *
    * @since S60 3.2.3
    * @param aBitmap a converted image.
    * @param aErr error code
    */
    virtual void ExtractAlbumArtCompleted(CFbsBitmap* aBitmap, TInt aErr ) = 0;

    };

#endif // MMPXALBUMARTUTILOBSERVER_H



