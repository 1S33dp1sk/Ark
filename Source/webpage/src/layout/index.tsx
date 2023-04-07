import React from 'react';
import { Navbar } from './Navbar';
import { Footer } from './Footer';
import useLocalStorage from 'use-local-storage';
import { ToastContainer } from 'react-toastify';


export const AppLayout = React.memo(function AppLayoutImpl(props: any) {
    const defaultDark = window.matchMedia('(prefers-color-scheme: dark)').matches;
    const [theme, setTheme] = useLocalStorage('theme', defaultDark ? 'dark' : 'light'); 

    return (
      <div data-theme={theme}>

          <Navbar theme={theme} setTheme={setTheme}/>
          {props.children}
          <Footer theme={theme}/>
          <ToastContainer/>

        </div>
    );
  });
  