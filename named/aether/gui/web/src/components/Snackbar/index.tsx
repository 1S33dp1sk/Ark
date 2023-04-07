import { useState, useEffect, FC, useCallback } from "react";
import ReactDOM from 'react-dom';
import { icons } from "../../assets";

/**
 * Neat Idea: When we integrate a state manager we can have a parent component that handles the display of notifications
 * instead of mounting them using reactDOM. Also we could use that container to render multiple notifications 
 * at once.
 */
export const Snackbar:FC<any> = (props:any) => {

    const [closeTimeout, setCloseTimeout] = useState<any>(null);


    const closeSnackBar = useCallback(() => {
        clearTimeout(closeTimeout);
        ReactDOM.unmountComponentAtNode(document.getElementById('snackbar-fixed-container') as HTMLElement);
    },[closeTimeout]);

    const beginCloseTimeout = useCallback(() => {
        if (props.timer) {
            const timeout = setTimeout(() => closeSnackBar(), props.timer);
            setCloseTimeout(timeout);
        }
    },[props.timer,closeSnackBar]);

    useEffect(() => {
        beginCloseTimeout();
    }, [beginCloseTimeout]);


    return (
        <div className={`snackbar-container ${props.messageType}-container`}
            onMouseEnter={() => clearTimeout(closeTimeout)}
            onMouseLeave={() => beginCloseTimeout()}>
            <div>
                <div className="snackbar-info-container">
                    <div>
                        <div className={`snackbar-icon ${props.messageType}-snackbar-icon`}></div>
                    </div>
                    <div>
                        <h5 className="rubik-text">{props.title}</h5>
                        <h5 className="muted-rubik-text">  {props.message}</h5>
                    </div>
                </div>
                <div>
                    <img src={icons.close} onClick={() => closeSnackBar()} alt="close icon" id="close-snackbar-icon" />
                </div>
            </div>
        </div>
    );
}