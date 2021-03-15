Game interface
==============

Here is the documentation for the game interface.


What is it ?
--------------

The game interface describes the abstract class containing all the functions in order to make a game in our Arcade board simulation.

Every functions has a specific goal and must be used because our Core will use every functions in a particular context.

.. note::

    An abstract class defines an abstract type which cannot be instantiated, but can be used as a base class.

Functions / API
---------------
Includes
~~~~~~~~
.. code-block:: c

    #include <Interface/IGames.hpp>


This header file contains the abstract class.

Interface
~~~~~~~~~
.. doxygenenum:: WinCondition
   :project: arcade
.. doxygenclass:: IGames
   :project: arcade
   :members: