
(async () => {
  console.log('[4Nums] poller online');

  const wasmURL = document.currentScript.dataset.wasm;   
  const { instance } =
        await WebAssembly.instantiateStreaming(fetch(wasmURL));
  const solve4 = instance.exports.solve4;
  const mem32  = new Int32Array(instance.exports.memory.buffer);
  console.log('[4Nums] wasm ready');


  let last = '';
  setInterval(() => {
    const q = window.quad;                   
    if (!Array.isArray(q) || q.length !== 4) return;

    const stamp = q.join(',');
    if (stamp === last) return;               
    last = stamp;

    console.log('[4Nums] digits →', q.slice());   

    /* run the solver */
    const ptr   = solve4(q[0], q[1], q[2], q[3]);
    const steps = mem32.subarray(ptr >> 2, (ptr >> 2) + 9);
    console.log('[4Nums] solver →', [...steps]);  
  }, 100);
})();
