#include "dictionary.h"

dictionary_t*
dictionaty_create ()
{
  dictionary_t *dictionary = malloc(sizeof(dictionary_t));
  dictionary->_data = trie_create();
}

void
dictionary_free (dictionary_t *dictionary)
{
  trie_free(dictionary->_data);
  free(dictionary);
}

bool
dictionaty_set (dictionary_t *dictionary, char *key, void *value)
{
  return trie_set(dictionary->_data, key, value);
}

void *
dictionaty_get (dictionary_t *dictionary, char *key)
{
  return trie_get(dictionary->_data, key);
}

bool
dictionaty_delete (dictionary_t *dictionary, char *key)
{
  return trie_delete(dictionary->_data, key);
}
