#include "slist.h"

#include <stdio.h>
#include <stdlib.h>

static slist_s *slistNew( void ) {
   slist_s *new_item = calloc(0, sizeof(slist_s));
   if (NULL == new_item) {
      printf("EMERG: Allocating new item failed - error(%m)\n");
   }

   return new_item;
}

slist_s *slistAdd(slist_s *list, void *data) {
   slist_s *new_item = slistNew();
   if (NULL != new_item) {
      new_item->data = data;
      new_item->next = list;
   }

   return new_item;
}

slist_s *slistSearch(slist_s *list, void *data) {
   slist_s *tmp = list;
   while ( (NULL != tmp) && (data != tmp->data) ) {
      tmp = tmp->next;
   }

   return tmp;
}

slist_s *slistNext(slist_s *list) {
   return (NULL != list) ? (list->next):NULL;
}

slist_s *slistRemove(slist_s **list, void *data) {
   slist_s *cur = *list;
   cur = slistSearch(cur, data);
   slist_s *tmp = NULL;

   if (NULL != cur) {
      tmp = cur->next;
      free(cur);
      cur= tmp;
   }

   return cur;
}

void slistDelete(slist_s **list) {
   slist_s *curr = *list;
   slist_s *next = NULL;

   while (NULL != curr) {
      next = curr->next;
      free(curr);
      curr = next;
   }

   *list = NULL;
}
