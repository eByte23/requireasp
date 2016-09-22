import { Home, HomeView } from '../Views/Home';
import { renderToString } from 'react-dom/server';

class HomeController{

    HomeView(model: HomeView): string{
        return renderToString(Home(model));
    }
}

export {HomeController};