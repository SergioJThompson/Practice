export function translate2d(dx, dy) {
  return function add(x, y) {
    return [x + dx, y + dy];
  };
}

export function scale2d(sx, sy) {
  return function multiply(x, y) {
    return [sx * x, sy * y];
  }
}

export function composeTransform(f, g) {
  return function(x, y) {
    let [fx, fy] = f(x, y)
    return g(fx, fy);
  }
}

export function memoizeTransform(f) {
  let memo = {}
  return function(x, y) {
    let result;
    if ([x, y] in memo)
      result = memo[[x, y]];
    else
      result = f(x, y);
    memo = {[[x, y]] : result};
    return result;
  };
}
