/*
 * The contents of this file are subject to the Mozilla Public
 * License Version 1.1 (the "License"); you may not use this file
 * except in compliance with the License. You may obtain a copy of
 * the License at http://www.mozilla.org/MPL/
 * 
 * Software distributed under the License is distributed on an "AS
 * IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
 * implied. See the License for the specific language governing
 * rights and limitations under the License.
 * 
 * The Original Code is TransforMiiX XSLT processor.
 * 
 * The Initial Developer of the Original Code is The MITRE Corporation.
 * Portions created by MITRE are Copyright (C) 1999 The MITRE Corporation.
 *
 * Portions created by Keith Visco as a Non MITRE employee,
 * (C) 1999 Keith Visco. All Rights Reserved.
 * 
 * Contributor(s): 
 * Keith Visco, kvisco@ziplink.net
 *    -- original author.
 * Bob Miller, kbob@oblix.com
 *    -- plugged core leak.
 *
 * $Id: StringList.h,v 1.3 1999-11-25 03:03:03 kvisco%ziplink.net Exp $
 */

/**
 * A class for keeping an ordered list of Strings
 * @author <a href="mailto:kvisco@ziplink.net">Keith Visco</a>
 * @version $Revision: 1.3 $ $Date: 1999-11-25 03:03:03 $
**/

#include "String.h"
#include "baseutils.h"

#ifndef MITREXSL_STRINGLIST_H
#define MITREXSL_STRINGLIST_H

class StringList {
   friend class StringListIterator;

   public:

      /**
       * Creates an empty StringList
      **/
      StringList();

      /**
       * StringList destructor
      **/
      ~StringList();

       MBool contains(String& search);

      /**
       * Returns the number of Strings in this List
      **/
      Int32 getLength();

      /**
       * Returns a StringListIterator for this StringList
      **/
      StringListIterator iterator();

      /**
       * Adds the given String to the list
      **/
      void add(String* strptr);

      /**
       * Removes the given String pointer from the list
      **/
      String* remove(String* strptr);

      /**
       * Removes all Strings equal to the given String from the list
       * All removed strings will be destroyed
      **/
      void remove(String& search);

protected:
    struct StringListItem {
        StringListItem* nextItem;
        StringListItem* prevItem;
        String* strptr;
    };

private:

      StringListItem* firstItem;
      StringListItem* lastItem;
      Int32 itemCount;

      void insertAfter(String* strptr, StringListItem* sItem);
      void insertBefore(String* strptr, StringListItem* sItem);

      /**
       * Removes the given StringListItem pointer from the list
      **/
      StringListItem* remove(StringListItem* sItem);
};




class StringListIterator {

public:


   StringListIterator(StringList* list);
   ~StringListIterator();

   void    add(String* strptr);

   MBool  hasNext();

   MBool  hasPrevious();

   String* next();

   String* previous();

   String* remove();

   void    reset();

private:

   StringList::StringListItem* currentItem;

   StringList* stringList;
   MBool allowRemove;
};

#endif

