
declare module Server {
    export var ScriptTimeout : number
    export function CreateObject(objectName : string) : Object
    export function Execute(filePath: string)
    export function GetLastError() : Object
    export function HTMLEncode(content : string) : string
    export function MapPath(relativePath : string) : string
    export function Transfer(filePath)
    export function URLEncode(content :string) : string
}
