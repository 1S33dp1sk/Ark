import twitter from './assets/icons/twitter.svg';
import discord from './assets/icons/discord.svg';
import yellow from './assets/maps/yellow.png';
import round from './assets/maps/round.png';
import brown from './assets/maps/brown.png';
import green from './assets/maps/green.png';
import macao from './assets/maps/macao.png';
import square from './assets/maps/square.png';
import script from './assets/icons/script.svg';
import a from './assets/members/a.png';
import b from './assets/members/b.png';
import c from './assets/members/c.png';
import don from './assets/members/don.png';


import './App.css';

function App() {
  return (
    <div>
      <div className="appbar">
         <nav>
          <h2><a href="/">GeoArt</a></h2>
          <ul>
            <li><a href="/">Home</a></li>
            <li><a href="#about">About</a></li>
            <li><a href="#minting">Minting</a></li>
            <li><a href="#team">Team</a></li>
              <ul>
                <li><a href="https://twitter.com/geoartnft" target="_blank"><img src={twitter}/></a></li>
                <li><a href="https://discord.gg/3jBwchjy7K" target="_blank"><img src={discord}/></a></li>
              </ul>
          </ul>
          </nav>
      </div>
      <div class="header-container">
        <div class="wrapper">
          <header>
            <div class="hero-image">
              <img src={yellow}/>
              </div>
            <div class="hero-content">
              <h1>Geo Art</h1>
              <ul>
              <p>
              Randomly selected coordinates from the 4.5 million cities around the world, where the system combines map elements with different colors, layers, and hatching patterns.
              </p>
              <p>
              The algorithm will generate 1000 unique images and artists add 80 custom locations together with manually picked design elements. </p>
              </ul>
            </div>
          </header>
        </div>
      </div>

      <div id="about">
      <div className="about">
          <h3>About The Art</h3>
          <ul>
          <p>
          The art is a combination of map layers,different HEX colors and patterns
          </p>
          </ul>
      </div>
      </div>
      <div className="features">
            <div class="left_text">
            <ul>
              <li>
                <img src={script}/>
                <h4>Basemap</h4>
                <p>The algorithm goes through the list of 4.5 million cities and takes random latitude and longitude. Based on that it extracts map elements from OpenStreetMap, which will be used as base elements for design.</p>
              </li>
              <li>
                <img src={script}/>
                <h4>Map elements</h4>
                <p>For each map element, the algorithm selects one color from HEX range, which means there are 16,777,216 possible combinations for each map element</p>
              </li>
              <li>
                <img src={script}/>
                <h4>Image frame</h4>
                <p>The image background and perimeter color are also chosen from the HEX color range. Moreover, the algorithm adds a random hatching pattern</p>
              </li>
            </ul>
            </div>
            <div class="feature_img">
              <img src={round}/>
            </div>
            <div class="right_text">
              <ul>
                <li>
                  <img src={script}/>
                  <h4>1000 machine-generated</h4>
                  <p>The algorithm will generate 1000 images based on different combinations and locations. Which will make each image different and unique</p>
                </li>

                <li>
                  <img src={script}/>
                  <h4>80 human-generated</h4>
                  <p>The team has defined few custom themes and matched them with some of the unique places all around the world</p>
                </li>
                <li>
                  <img src={script}/>
                  <h4>Traits and rarity</h4>
                  <p>There are different traits for images, including theme, radiuses, country, generation method, etc. Part of the rarity comes from the algorithm and another from the human-generated options</p>
                </li>
              </ul>
              </div>
      </div>
      <div id="minting">
      <div className="minting-container">
        <div class="minting">
          <div class="image">
            <img src={square}/>
          </div>
          <div class="text">
            <h4>Minting</h4>
            <p>Price per token - <b>0.15 ETH</b></p>
            <p>Maximum tokens per transaction - <b> 20 </b> </p>
            <p>Total number of tokens - <b> 1080 </b></p>
          </div>
      </div>
      <div class="setup">
        <div class="text">
          <h4>Setup</h4>
          <p>Geo Art is built on top of ERC-721 smart contract and generated files will be hosted on IPFS  </p>
        </div>
        <div class="image">
          <img src={green}/>
        </div>
    </div>
      </div>
      </div>


      <div id="team">
      <div className="team">
        <h3>About the team</h3>
        <h4>Our goal is to build creative art which is unique and beautiful, something that can set an example and inspire other artists</h4>
        <ul>
          <li>
            <img src={a}/>
            <h5><a href="https://twitter.com/imoosov" target="_blank">@imoosov</a></h5>
            <p>Has been building tech products for more than 10 years. Generated geo art for birthday presents and believes this journey is a beginning of something bigger.</p>
          </li>
          <li>
            <img src={b}/>
            <h5>@karam</h5>
            <p>Tech enthusiastic who has been in crypto since BTC was 3000$. Our tech lead and smart contract developer</p>
          </li>

          <li>
            <img src={c}/>
            <h5><a href="https://twitter.com/marceloprates_" target="_blank">@marceloprates_</a></h5>
            <p>AI Researcher @ Samsung, PhD from UFRGS. Marcelo has built the plot script which enables to draw customized maps from OpenStreetMap</p>
          </li>
        </ul>
      </div>
      </div>

      <div className="donation">
            <div class="don-desc">
                <h4>Donations</h4>
                <p><b>5%</b> of the successful sales will be donated to OpenStreetMap Foundation, so that they can keep their servers running and support similar art projects.</p>
                <p><b>10%</b> of it will be donated to nature, to plant trees. Without nature, we wouldnt have life https://trees.org/.</p>
            </div>
            <div class="don-img">
                <img src={don}/>
            </div>
      </div>

      <div className="ftr">
          <ul>
          <li><a href="/">Home</a></li>
          <li><a href="#about">About</a></li>
          <li><a href="#minting">Minting</a></li>
          <li><a href="#team">Team</a></li>
          </ul>
          <p>GeoArt 2021</p>
      </div>
    </div>
  );
}

export default App;
