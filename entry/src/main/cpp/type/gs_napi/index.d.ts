declare module "gs_napi" {
  export function convert(pdfPath: string, pclmPath: string): number;
  const _default: { convert: typeof convert };
  export default _default;
}
