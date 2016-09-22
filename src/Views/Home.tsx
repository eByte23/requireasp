import * as React from 'react';
interface HomeView{
    Title: string;
}
const Home = (props:HomeView) => {
    return (
        <div>
            <div style={{ color: "blue" }}>{props.Title}</div>
        </div>
    )
}

export {Home, HomeView};