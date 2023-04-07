import { FC, useLayoutEffect, useState } from "react";
import { Link, useParams } from "react-router-dom";
import { icons } from "../../assets";
import { DOCS } from "../../constants";
import { AETHER_DOCS } from './.backup'


export const Guides: FC<any> = (props: any, docu: any) => {
  const [guide, setGuide] = useState<string>("0xAether");
  const { guide_desc } = useParams();
  const [docDesc, setDocDesc] = useState("Essentials");
  const [width, setWidth] = useState<number>(window.innerWidth);

  useLayoutEffect(() => {
    window.addEventListener('resize', handleWindowSizeChange);
    return () => {
        window.removeEventListener('resize', handleWindowSizeChange);
    }
  }, []);
  function handleWindowSizeChange() {
    setWidth(window.innerWidth);
  };
  function refreshGuide(_guide: string) {
    if (_guide === "0xAether") {
      setDocDesc("Essentials");
    } else {
      setDocDesc("Installation");
    }
    setGuide(_guide);
  };

  function togglePath(type: string) {
    setDocDesc(type);
    window.location.replace(`guides#${guide}/${type}`);
    mobileMenu()
  };

  function getDocumentation(desc: string) {
    return (
      <section
        id={guide_desc}
        dangerouslySetInnerHTML={{ __html: (AETHER_DOCS as any)[desc].iihtml }}
      />
    );
  };

  function mobileMenu() {
    if(width <= 992){

      var sec = document.getElementById("nav_sec");
      var dox = document.getElementById("docs_body");
      if (sec?.className === "nav_sec") {
        sec.className += " res";
        dox!.className += "hid";
      } else {
        dox!.className = "docs_body";
        sec!.className = "nav_sec";
      }
  }

  };

  return (
    <div className="docs">
      {/* needed for github, please keep this here. */}
      <img src={icons.athr_blk} style={{ display: "none" }} alt="" />
      <img src={icons.athr_wht} style={{ display: "none" }} alt="" />
      <nav className="left_menu">
        <h1>Guides</h1>
        <div id="nav_sec" className="nav_sec">
          {Object.keys(DOCS).map((d, idx) => (
            <div className="gds" key={idx}>
              <Link
                to={`/guides#${d}`}
                onClick={() => refreshGuide(d)}
                style={{ opacity: d === guide ? 1 : 0.4 }}
              >
                {d}
              </Link>
            </div>
          ))}
          <ul>
            {(DOCS as any)[guide]["childs"].map((c: any, idx: number) => (
              <li key={idx}>
                <h2>{c.title}</h2>
                <ol>
                  {c.branches.map((b: any, idx: number) => (
                    <li
                      key={idx}
                      onClick={() => togglePath(b)}
                      style={{ opacity: docDesc === b ? 1 : 0.5 }}
                    >
                      {b}
                    </li>
                  ))}
                </ol>
              </li>
            ))}
          </ul>
        </div>
        <div className="nav-m" id="nav-m" onClick={() => mobileMenu()}>
          <img src={icons.menu} alt="" />
        </div>
      </nav>
      <div className="docs_body" id="docs_body">
          <h1 className="main_title">{docDesc}</h1>
          {getDocumentation(docDesc)}
      </div>
    </div>
  );
};
