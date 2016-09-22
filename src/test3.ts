/// <reference path="./Server.d.ts" />
/// <reference path="./Request.d.ts" />

let GetFileUrl = (path: string) :string => {
    return Server.MapPath(path);
}

let CheckVars = (varCheck: string): boolean => {
    return false//.ServerVariables.ContainsKey(varCheck);
}

export { GetFileUrl , CheckVars}


