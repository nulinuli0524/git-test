const path = require('path');
const addon = require('node-gyp-build')(path.resolve(__dirname));
module.exports = addon;
