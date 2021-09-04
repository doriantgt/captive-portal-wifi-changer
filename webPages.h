


const char HTML[] PROGMEM = "<form   action=\"/hello\" ><label class=\"label\">Network Name</label><input type=\"text\" name=\"ssid\"/><br/><label>Password</label><input type=\"text\" name=\"pass\"/><br/><input type=\"submit\" value=\"Submit\"></form>";

//you need a splash page if you plan to use processor with captive portal
const char splash[] PROGMEM = R"rawliteral( 
    <!DOCTYPE HTML><html><head>
      <title>Splash Page</title>
      <meta name="viewport" content="width=device-width, initial-scale=1">
    <a href="/index">click here</a>
)rawliteral";

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html><head>
  <title>ESP Input Form</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <script>
    function submitMessage() {
      alert("Saved value to ESP SPIFFS");
      setTimeout(function(){ document.location.reload(false); }, 500);  //this is why we reload the same page  
    }
  </script></head><body>
  <form action="/post" target="hidden-form" method="post">
    wifi name (current value::%wifi%): <input type="text" name="wifi">
    <input type="submit" value="Submit" onclick="submitMessage()">
  </form><br>
  <form action="/post" target="hidden-form" method="post">
    wifi password (current value::%password%): <input type="text" name="password">
    <input type="submit" value="Submit" onclick="submitMessage()">
  </form><br>
  current time = %time%

  <iframe style="display:none" name="hidden-form"></iframe>
   <p style="color:%fontcolor%">%connectionStatis%</p>
    <a href="/index">refresh</a>
      <a href="http://www.google.com">google</a>
    </body></html>
)rawliteral";

