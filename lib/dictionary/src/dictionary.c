#include "dictionary/dictionary.h"

Dictionary*
dictionaty_create ()
{
  Dictionary *dictionary = malloc(sizeof(Dictionary));
  dictionary->_data = trie_create();
  return dictionary;
}

void
dictionary_free (Dictionary *dictionary)
{
  trie_free(dictionary->_data);
  free(dictionary);
}

bool
dictionaty_set (Dictionary *dictionary, char *key, void *value)
{
  return trie_set(dictionary->_data, key, value);
}

void *
dictionaty_get (Dictionary *dictionary, char *key)
{
  return trie_get(dictionary->_data, key);
}

bool
dictionaty_delete (Dictionary *dictionary, char *key)
{
  return trie_delete(dictionary->_data, key);
}
