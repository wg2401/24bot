console.log('bot loaded');

const url = chrome.runtime.getURL('page-poller.js');
const s   = document.createElement('script');
s.src     = url;
(document.head || document.documentElement).appendChild(s);
s.remove();               
