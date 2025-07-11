
(async () => {
  console.log('[4Nums] poller online');

  //get solver wasm
  const wasmURL = document.currentScript.dataset.wasm;   
  const { instance } = await WebAssembly.instantiateStreaming(fetch(wasmURL));
  const solve4 = instance.exports.solve4;
  const mem32  = new Int32Array(instance.exports.memory.buffer);
  console.log('[4Nums] wasm ready');


  //set up for key inputs
  const canvas = document.getElementById('canvasID');      
  const press = (code) => {
    const ev = new KeyboardEvent('keydown', {
      bubbles : true,
      keyCode : code,
      which   : code,
    });
    canvas.dispatchEvent(ev);
  };

  const keyNum = [ 0, 49, 50, 51, 52 ];        // 1,2,3,4 key inputs
  const keyOp  = [ 81, 87, 69, 82 ];           // 0:+(q) 1:-(w) 2:×(e) 3:÷(r)
  const ESC    = 27;

  const pause  = (ms=65) => new Promise(r => setTimeout(r, ms));

  let last = '';
  setInterval(async() => {
    const q = window.quad;                   
    if (!Array.isArray(q) || q.length !== 4) return;

    const stamp = q.join(',');
    // if (stamp === last) return;               
    last = stamp;

    console.log('[4Nums] digits →', q.slice());   

    /* run the solver */
    const ptr   = solve4(q[0], q[1], q[2], q[3]);
    const steps = mem32.subarray(ptr >> 2, (ptr >> 2) + 9);
    console.log('[4Nums] solver →', [...steps]);

    for (let k = 0; k < 3; k++) {
      const idx1 = steps[k*3 + 0];      
      const opId = steps[k*3 + 1];      
      const idx2 = steps[k*3 + 2];        

      press(keyNum[idx1]);  
      press(keyOp[opId]);   
      press(keyNum[idx2]); 
    }

    press(ESC);      

  }, 100);
})();
