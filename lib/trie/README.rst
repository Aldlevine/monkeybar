================================================================================
Trie
================================================================================

The trie library implements a trie (radix tree) to store arbitrary data by association to string identifiers. (key value store). Keys accept a character array made up of a defined set of ascii characters.


--------------------------------------------------------------------------------
Valid key characters
--------------------------------------------------------------------------------
- ``a - z``
- ``A - Z``
- ``0 - 9``
- Special characters

  - ``$ - _``

--------------------------------------------------------------------------------
API
--------------------------------------------------------------------------------

trie_create
--------------------------------------------------------------------------------
``trie_node_t *trie_create (void)``

Creates a ``trie_node_t`` to use as a root node

+--------+-----------------------------+
| return | a ``trie_node_t`` root node |
+--------+-----------------------------+


trie_set
-------------------------------------------------------------------------------
``bool  trie_set (trie_node_t *root, char *key,
void *value)``

Sets ``key`` to ``value``

======= ================================
param   description
======= ================================
root    the ``trie_node`` to insert into
key     the key to set
value   the value to set ``key`` to
======= ================================

+--------+---------------------------------------------+
| return | ``true`` if successful, ``false`` otherwise |
+--------+---------------------------------------------+


trie_get
--------------------------------------------------------------------------------
``void* trie_get (trie_node_t *root, char *key)``

Gets ``value`` at ``key``

======= =================================
param   description
======= =================================
root    the ``trie_node`` holding the value
key     the key where ``value`` is set
======= =================================

+--------+---------------------------------------------+
| return | ``value`` if exists, ``NULL`` otherwise     | 
+--------+---------------------------------------------+

