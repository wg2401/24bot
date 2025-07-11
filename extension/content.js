
console.log('[4Nums] content.js loaded');

const pollerSrc = chrome.runtime.getURL('page-poller.js');
const wasmSrc   = chrome.runtime.getURL('solver.wasm');


const s         = document.createElement('script');
s.src           = pollerSrc;
s.type          = 'text/javascript';
s.dataset.wasm  = wasmSrc;        

(document.head || document.documentElement).appendChild(s);
s.remove();                      
