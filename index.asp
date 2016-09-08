<%@ LANGUAGE=JavaScript %>
<!--#include file="require.inc" -->
<html>
    <body>
        <%
            var userFeatures = require("userfeatures", true);
            var code2 = require("./Test/code2");

            Response.Write("Page loaded");
        %>
        </br>

        App Pool user is: <%=userFeatures.getAppUser() %>
        </br>
        Windows user is: <%=userFeatures.getWindowsAuthUser() %>

    </body>
</html>