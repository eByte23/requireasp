/// <reference path="./Dictionary.d.ts" />

declare module Request {
    export var Body: Dictionary;
    export var ClientCertificates: Dictionary;
    export var Cookies: Dictionary;
    export var Item: any;
    export var QueryString : Dictionary;
    export var ServerVariables: Dictionary;
    export var ToalBytes: number;
}