#include "dictionary.h"

Dictionary*
dictionary_create (char *first, ...)
{
  Dictionary *dictionary = malloc(sizeof(Dictionary));
  dictionary->_data = trie_create();


  if (first != NULL)
  {
    va_list ap;
    va_start(ap, first);
    /* {{{ */
      char *key = first;
      void *value = va_arg(ap, void *);
      trie_set(dictionary->_data, key, value);
      for (;;)
      {
        key = va_arg(ap, char *);
        if (key == NULL) { break; }
        value = va_arg(ap, void *);
        trie_set(dictionary->_data, key, value);
      }

      /* char *key; */
      /* void *value; */
      /* for (size_t i=0; i<count*2; i+=2) */
      /* { */
        /* key = va_arg(ap, char *); */
        /* value = va_arg(ap, void *); */
        /* trie_set(dictionary->_data, key, value); */
      /* } */

    /* }}} */
    va_end(ap);
  }

  return dictionary;
}

void
dictionary_free (Dictionary *dictionary)
{
  trie_free(dictionary->_data);
  free(dictionary);
}

bool
dictionary_set (Dictionary *dictionary, char *key, void *value)
{
  return trie_set(dictionary->_data, key, value);
}

void *
dictionary_get (Dictionary *dictionary, char *key)
{
  return trie_get(dictionary->_data, key);
}

bool
dictionary_delete (Dictionary *dictionary, char *key)
{
  return trie_delete(dictionary->_data, key);
}
