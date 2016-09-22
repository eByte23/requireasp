<%
var __require_context_path = __require_context_path || null;

var require = function(file, debug) {
		if(debug) {
			_requireHelpers.setDebug(debug);
		}
        //__require_context_path = __require_context_path || null;
        if(__require_context_path != null){
            file = Server.Map(__require_context_path) +file;
        }

        return _requireHelpers.getRequiredFile(file, debug);
}

var _requireHelpers = {
        getRequiredFile: function(file, debug){
            var scriptFileInfo = this._getFile(file, ".js");
            if(!scriptFileInfo.exists && debug){
                Response.Write("<b>VIEW SOURCE</b><br/>"+scriptFileInfo.filePath+"does not exist");
                return;
            }

            return this._compile(scriptFileInfo,debug);
        },
        setDebug : function(debug) {
            debug !== "undefined" ? debug : false;
            this._debug = debug;
        },
        isDebug : function(){
            return _debug;
        },
        _debug : false,
        _getFile : function(file, ext) {

            ext = typeof (ext) !== "undefined" ? ext : ".js";
            var fileWithExt = file + ext;

            var filePath = Server.MapPath(fileWithExt);

            var fs = Server.CreateObject("Scripting.FileSystemObject"),
                fContent,
                fReader;

            var fileExists = fs.FileExists(filePath);

            if(fileExists) {
                fReader = fs.OpenTextFile(filePath,1,false);
                fContent = fReader.ReadAll();
                fReader.close();
            } else {
                fContent = "";
            }
            fs = null;

            return fileInfo(file, filePath, fileWithExt, fileExists, fContent);

        },
        _compile : function(fileInfo) {
            function escapeCode(str) {
                return str.replace(/'/gm, "\\'").split('\r').join('\\r').split('\n').join('\\n');
            }

            function stripChars(str) {
                str = str.split("\\r").join("").split("\\n").join("");
                return str;
            }

            var text = fileInfo.fileContent;
            var requireBaseArr = fileInfo.filePath.split('/')
            __require_context_path = requireBaseArr.splice(0,requireBaseArr.length-1).join('/') +"/";
            var funcBody = "var exports = exports || {};";
            funcBody += text;
            funcBody += "\r\n return exports;";

            if (this._debug && funcBody.length > 0) {
                Response.Write("<br/><b>VIEW SOURCE</b>: "+ fileInfo.fileName +"<br/>")
				Response.Write(Server.HtmlEncode(funcBody).replace(/try/g, "<br/>try").replace(/\\r/g,"").replace(/\\n/g,""));
			}

            try {
                var abc = new Function(funcBody);
                return abc();
            }
            catch(e) {
                Server.Execute(fileInfo.filePath);
            }
            return new Function();
        }
}

var fileInfo = function(fileName, fileExt, filePath, exists, content) {
	return {
		exists : exists,
		fileName : fileName,
		filePath : filePath,
		fileExtenion : fileExt,
		fileContent : content
	}
}
%>
