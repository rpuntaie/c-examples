C++ Examples
------------

| github: I changed the ``++`` to ``-``.
| me: No! What did you do?
| github: ``-``
| me: Never mind.

Learning is best done by examples.

This is a collection of C++ examples
from various sources.

Folders

- r: various sources
- c: c examples from `cppreference.com`_
- cpp: cpp examples from `cppreference.com`_

The `cppreference.com`_ examples were extracted with ``cppreference_com_examples.py``.

**Pull requests** with further examples are welcome.

Each example file contains the command to compile the file
in a line starting with ``g++``, ``gcc`` or ``clang``.
It places the result in ``../_build``.

To compile and run all examples:

.. code:: sh

  bash tryall.sh

Or with `doit <https://github.com/pydoit/doit>`__,
using 7 processes and without stopping after failed commands:

.. code:: sh

  doit --continue -n 7
  #uses dodo.py


.. _`cppreference.com`: https://en.cppreference.com
