## RequireASP

### Require for asp classic

How to use require
```
//Put this at the top of your asp classic file
<%@ LANGUAGE=JavaScript %>
<!--#include file="require.inc" -->

//lets require an object from file
var userFeatures = require("userfeatures");

//enable debug
var userFeatures = require("userfeatures", true);


```

Happy days :)