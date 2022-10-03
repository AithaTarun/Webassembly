
// Express
const express = require('express');
const app = express();

try
{
  app.use //To handle CORS error.
    (
      (request,response,next)=>
      {
        response.setHeader
        (
          'Access-Control-Allow-Origin',
          '*'
        );
        
        response.setHeader
        (
          "Cross-Origin-Embedder-Policy", 
          "require-corp"
        );
        
        response.setHeader
        (
          "Cross-Origin-Opener-Policy", 
          "same-origin"
        );
        

        response.setHeader
        (
          'Access-Control-Allow-Headers',
          'Origin, X-Requested-With, Content-Type, Accept, Authorization'
        );

        response.setHeader
        (
          'Access-Control-Allow-Methods',
          'GET, POST, PATCH, DELETE, OPTIONS, PUT'
        );

        response.setHeader
        (
          'Access-Control-Allow-Credentials',
          'true'
        )

        next();
      }
    );
}
catch (e)
{
  console.log("Error occurred :", e)
}

// Serve static files from /public
app.use( express.static('public', {
  setHeaders: (res, path, stat) => {
    // Serve .wasm files with correct mime type
    if (path.endsWith('.wasm')) {
      res.set('Content-Type', 'application/wasm')
    }
  }
}) )

// Start server
app.listen( 2222, () => console.log('Server running on port 2222!') )
