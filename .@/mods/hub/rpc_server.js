#!/usr/local/bin/node


const http = require('http');

const server = http.createServer((req, res) => {
    if (req.method === 'POST' && req.url === '/rpc') {
        let requestData = '';
        req.on('data', chunk => {
            requestData += chunk;
        });

        req.on('end', () => {
            const requestTimestamp = new Date().toISOString();
            console.log(`Request timestamp: ${requestTimestamp}`);
            const requestBody = JSON.parse(requestData);
            console.log('Received JSON: ', requestBody);

            for (const item in requestBody) {
                console.log(`${item}: ${requestBody[item]}`);
            }

            const response = {
                ...requestBody,
                requestTimestamp,
            };

            res.setHeader('Content-Type', 'application/json');
            res.write(JSON.stringify(response));
            res.end();
        });
    }
});

const PORT = process.env.PORT || 3000;
server.listen(PORT, () => {
    console.log(`Echo RPC server listening on port ${PORT}`);
});