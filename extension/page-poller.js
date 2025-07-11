
(function () {
  


  let last = '';
  setInterval(() => {
    const q = window.quad;
    if (Array.isArray(q) && q.length === 4) {
      const stamp = q.join(',');
      if (stamp !== last) {
        last = stamp;
        console.log('[4Nums] digits →', q.slice());
      }



    }
  }, 100);
})();
