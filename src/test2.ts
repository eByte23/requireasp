import { GetFileUrl , CheckVars} from './test3';

class Hello {

    public constructor(name:string) {
            this.Name = name;
    }

        public Name: string;
    public DoSomething () :string {
        return "ok"
        }

    public GetFileUrl(): string {
        return GetFileUrl("./base64.js");
    }

    public DoesUrlExist(): boolean{
        return CheckVars("URL");
    }
}

export {Hello};
