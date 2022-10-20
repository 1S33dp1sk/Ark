import { FC } from "react"
import { images } from "../../assets"
import { FOOTER, SOCILAS } from "../../constants"


export const Footer:FC<any> = (props:any) => {

    
    return(
        <div className="ftr" >
            <div>
                <ul className="ftr_cont">
                    {FOOTER.map((t,idx) => 
                    <li key={idx}>
                        {t.title}
                        <ul>
                            {t.childs.map((c,idx) => 
                            <li key={idx}>
                                <a href={c.link}>{c.title}</a>
                            </li>
                        )}
                        </ul>
                    </li>
                    )}
                </ul>
                 <ul className="socs">{SOCILAS.map((s, idx) => 
                        <li key={idx}>
                            <a href={s.link} target="_blank" rel="noreferrer"><img src={s.logo} alt=""/></a>
                        </li>
                    )}
                </ul>
            </div>
            <section>
            <img src={props.theme === "dark" ? images.b_logo : images.w_logo} alt="LOGO" />
                <p>©Aetherlabs Inc 2022. All rights reserved.</p>
            </section>
        </div>
    )
}