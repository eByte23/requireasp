<%@ LANGUAGE=JavaScript %>
<!--#include file="require.inc" -->
<html>
    <body>
        <%
            var hmView = require("./Controller/Home");

            var ctl = new hmView.HomeController();



            //Response.Write(a.Name);
        %>

        <%= ctl.HomeView({Title: "Hello"}) %>
        </br>

        App Pool user is:
        </br>
        Windows user is:
    </body>
</html>