
Turbo Meteor is a simple example of how to do line-based animation under
windows.  There is much room for improvement in this example.  The
following are some suggested improvement you can make:

Improved collision detection:  currently, Turbo Meteor uses simple bounding
rectangle tests for collision detection.  This is fast, but innacurrate.
A faster method would be to use bounding circles for the quick test, and
then a full point-in-polygon test for the final test.

Object type identification:  All the sprites are stored in a single list.
This creates a problem when testing for collisions, because we only want
to check for collisions between shots and meteors, not between shots and
other shots.  So as we traverse the list, we must query each object to
see what type it is.  Currently this is done based on a 'name' member of
each object.  This is slow, because it requires a strcmp() call.  A better
way would be to either use RTTI, or implement a simple 'type' member which
is an integer instead of a string.





